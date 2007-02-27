// scene.cpp - Implementation of scene class

/*
  Copyright (C) 2007 Jeremiah LaRocco

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

#include "scene.h"

GridEntry::GridEntry() : objCount(0) {
}

GridEntry::~GridEntry() {
  objects.clear();
  lights.clear();
}
void GridEntry::addObject(Object *obj) {
  objects.insert(obj);
  obj->incCellCount();
  ++objCount;
}
void GridEntry::addLight(Light *lght) {
  lights.insert(lght);
}
int GridEntry::getNumObjs() {
  return objCount;
}
  
Intersection GridEntry::intersect(Ray r, bool computeNorm, unsigned int *int_test, unsigned int *int_hit) {
  Intersection bestIsect(9.9e99, false);
  if (objects.size()==0) {
      return bestIsect;
  }
  Intersection curIsect;
  for (ObjectList::iterator obj_iter = objects.begin();
      obj_iter != objects.end();
       ++obj_iter) {
    curIsect = (*obj_iter)->intersect(r, computeNorm);
    (*int_test)++;
    if (curIsect.hits()) {
      ++(*int_hit);
      if (curIsect.t()<bestIsect.t()) {
	bestIsect = curIsect;
	bestIsect.setGridEntry(this);
      }
    }
  }
  return bestIsect;
}

Scene::Scene(Camera camera,
	     Color bColor,
	     real xmin, real xmax,
	     real ymin, real ymax,
	     real zmin, real zmax,
	     size_t w,
	     size_t h,
	     size_t d) : cam(camera),
			 bgColor(bColor),
			 x_min(xmin), x_max(xmax),
			 y_min(ymin), y_max(ymax),
			 z_min(zmin), z_max(zmax),
			 width(w), height(h),
			 depth(d), rays_cast(0),
			 reflective_rays_cast(0),
			 refractive_rays_cast(0),
			 shadow_rays_cast(0),
			 intersections(0),
			 intersection_tests(0) {
  theGrid.reserve(width);
  for (size_t i=0;i<width; ++i) {
    theGrid.push_back(grid_plane_t(height));
    for (size_t j=0; j<height; ++j) {
      theGrid[i].push_back(grid_row_t(depth));
      for (size_t k=0; k<depth; ++k) {
	theGrid[i][j].push_back(new GridEntry());
      }
    }
  }
}

Scene::~Scene() {
  for (size_t i=0;i<width; ++i) {
    for (size_t j=0; j<height; ++j) {
      for (size_t k=0; k<depth; ++k) {
	delete theGrid[i][j][k];
      }
      theGrid[i][j].resize(0);
    }
    theGrid[i].resize(0);
  }
  theGrid.resize(0);

  for (ObjectList::iterator obj_iter = objects.begin();
       obj_iter != objects.end();
       ++obj_iter) {
    delete (*obj_iter);
  }

  for (LightList::iterator lt_iter = lights.begin();
       lt_iter != lights.end();
       ++lt_iter) {
    delete (*lt_iter);
  }

  objects.clear();
  lights.clear();
}

void Scene::addObject(Object *obj) {
  objects.insert(obj);
  static real xdiff = real(width)/(x_max - x_min);
  static real ydiff = real(height)/(y_max - y_min);
  static real zdiff = real(depth)/(z_max - z_min);
  
  real xmin, xmax, ymin, ymax, zmin, zmax;
  real temp;
  size_t x_idx1, y_idx1, z_idx1;
  size_t x_idx2, y_idx2, z_idx2;
  
  obj->getExtents(xmin, xmax, ymin, ymax, zmin, zmax);

  xmin -= std::ceil(std::fmod(xmin, xdiff))*xdiff;
  ymin -= std::ceil(std::fmod(ymin, ydiff))*ydiff;
  zmin -= std::ceil(std::fmod(zmin, zdiff))*zdiff;
  
  xmax += std::ceil(std::fmod(xmax, xdiff))*xdiff;
  ymax += std::ceil(std::fmod(ymax, ydiff))*ydiff;
  zmax += std::ceil(std::fmod(zmax, zdiff))*zdiff;
  
  temp = (xmin-x_min)*xdiff;
  x_idx1 = std::max(int(std::floor(temp)), 0);
  
  temp = (xmax-x_min)*xdiff;
  x_idx2 = std::min(int(std::ceil(temp)), int(width-1));
  
  temp = (ymin-y_min)*ydiff;
  y_idx1 = std::max(int(std::floor(temp)), 0);
  
  temp = (ymax-y_min)*ydiff;
  y_idx2 = std::min(int(std::ceil(temp)), int(height-1));

  temp = (zmin-z_min)*zdiff;
  z_idx1 = std::max(int(std::floor(temp)), 0);
  
  temp = (zmax-z_min)*zdiff;
  z_idx2 = std::min(int(std::ceil(temp)), int(depth-1));
  
  for (size_t x = x_idx1; x <= x_idx2; ++x) {
    for (size_t y = y_idx1; y <= y_idx2; ++y) {
      for (size_t z = z_idx1; z <= z_idx2; ++z) {
	theGrid[x][y][z]->addObject(obj);
	
      }
    }
  }
}
void Scene::getGridStats(real &mean, real &stdDeviation,
			 real &variance, int &min, int &max,
			 real &meanCells, real &stdDeviationCells,
			 real &varianceCells,
			 int &minCells, int &maxCells) {
  int total = 0;
  int squareTotal = 0;
  int maximum = std::numeric_limits<int>::min();
  int minimum = std::numeric_limits<int>::max();
  int count;
  for (size_t x = 0; x < width; ++x) {
    for (size_t y = 0; y < height ; ++y) {
      for (size_t z = 0; z < depth ; ++z) {
	count = theGrid[x][y][z]->getNumObjs();
	squareTotal += count*count;
	total += count;
	minimum = std::min(minimum, count);
	maximum = std::max(maximum, count);
      }
    }
  }
  mean = real(total)/getNumCells();
  variance = real(squareTotal)/getNumCells()-mean*mean;
  stdDeviation = std::sqrt(variance);
  min = minimum;
  max = maximum;

  maximum = std::numeric_limits<int>::min();
  minimum = std::numeric_limits<int>::max();
  total = 0;
  squareTotal = 0;
  for (ObjectList::iterator iter = objects.begin();
       iter != objects.end();
       ++iter) {
    count = (*iter)->getNumCells();
    total += count;
    squareTotal += count*count;
    minimum = std::min(minimum, count);
    maximum = std::max(maximum, count);
  }
  meanCells = real(total)/objects.size();
  minCells = minimum;
  maxCells = maximum;
  varianceCells = real(squareTotal)/objects.size()-mean*mean;
  stdDeviationCells = std::sqrt(varianceCells);
  
}
int Scene::getNumCells() {
  return width*height*depth;
}


void Scene::getIdxOfPoint(real x, real y, real z,
			  size_t &xidx,
			  size_t &yidx,
			  size_t &zidx) {
  static real xdiff = real(width)/(x_max - x_min);
  static real ydiff = real(height)/(y_max - y_min);
  static real zdiff = real(depth)/(z_max - z_min);

  real temp;
  temp = (x-x_min)*xdiff;
  xidx = size_t(std::floor(temp));
  
  temp = (y-y_min)*ydiff;
  yidx = size_t(std::floor(temp));
  
  temp = (z-z_min)*zdiff;
  zidx = size_t(std::floor(temp));
}

Intersection Scene::rtrace(Ray r, bool computeNorm, Object *curObj) {
  ++rays_cast;
  Intersection bestIsect(9e99, false);
  size_t xi, yi, zi;
  int signx, signy, signz;
  int exy,exz,ezy;
  
  int rdx = int(std::floor(r.getDir().normal().i()*x_max));
  int rdy = int(std::floor(r.getDir().normal().j()*y_max));
  int rdz = int(std::floor(r.getDir().normal().k()*z_max));
  
  int absRdx(std::abs(rdx));
  int absRdy(std::abs(rdy));
  int absRdz(std::abs(rdz));
  
  getIdxOfPoint(r.getOrigin().x(),
		r.getOrigin().y(),
		r.getOrigin().z(),
		xi, yi, zi);

  exy = rdy-rdx;
  exz = rdz-rdx;
  ezy = rdy-rdz;

  signx=1;
  if (rdx<0.0)
    signx=-1;
  
  signy=1;
  if (rdy<0.0)
    signy=-1;
  
  signz=1;
  if (rdz < 0.0)
    signz=-1;
  while ((xi<width)
	 && (yi<height)
	 && (zi<depth)
	 && (xi>=0)
	 && (yi>=0)
	 && (zi>=0)) {
    bestIsect = theGrid[xi][yi][zi]->intersect(r,
					       computeNorm,
					       &intersection_tests,
					       &intersections);
    if (bestIsect.hits()
	&& (bestIsect.object()!=curObj)
	&& bestIsect.getGridEntry()==theGrid[xi][yi][zi]) {
      return bestIsect;
    }
    if (exy<0) {
      // Not y adjacent
      if (exz <0) {
	// X adjacent
	xi  +=  signx;
	exy += absRdy;
	exz += absRdz;
      } else {
	// Z adjacent
	zi  +=  signz;
	exz -= absRdx;
	ezy += absRdy;  // Changed from ezy
      }
    } else {
      // Possibly y adjacent
      if (ezy < 0) {
	// Z adjacent
	zi  +=  signz;
	exz -= absRdx;
	ezy += absRdy;
      } else {
	// Y adjacent
	yi  +=  signy;
	exy -= absRdx;
	ezy -= absRdz;
      }
    }
  }
  return bestIsect;
}

Color Scene::shade(Intersection isect, Ray r, int level) {
  if (!isect.hits()) {
    return bgColor;
  }
  real eps;
  if (r.in()) {
    eps = 0.00001;
  } else {
    eps = -0.00001;
  }
  
  Texture *txt = isect.object()->getTexture();
  Point isectPt = r.pointOn(isect.t());
  
  Color curColor(0.0,0.0,0.0);
  Color specular(0,0,0);
  Color diffuse(0,0,0);
  Color shadowAmt(1,1,1);
  
  for (LightList::iterator lt_iter = lights.begin();
       lt_iter != lights.end();
       ++lt_iter) {

    Vector specL((*lt_iter)->location()-isectPt);
    Vector specV(cam.getLocation()-isectPt);
    Vector specHj((specL+specV)*(1.0/((specL+specV).length())));

    Ray shade_ray = (*lt_iter)->getRayTo(r.pointOn(isect.t()+ eps));

    ++shadow_rays_cast;
    Intersection tempI = rtrace(shade_ray, true, isect.object());
    if (tempI.hits()) {
      if (level>0) {
	shadowAmt -= shade(tempI, shade_ray, level-1);
      } else {
	shadowAmt = Color(0.0,0.0,0.0);
      }
    }

    specular += (*lt_iter)->intensity()*std::pow(specHj.dot(isect.normal()), txt->n());
    diffuse += (*lt_iter)->intensity()*shade_ray.getDir().dot(isect.normal());
  }
  shadowAmt *= 1.0/real(lights.size());
  
  Color reflective(0.0,0.0,0.0,0.0);
  if ((level>0)
      && (txt->kr().intensity()>0.01)) {
    ++reflective_rays_cast;
    Ray tempRay(r.pointOn(isect.t()+eps),
		r.getDir()
		- 2.0
		* (r.getDir().dot(isect.normal()))
		* isect.normal());
    reflective = shade(rtrace(tempRay), tempRay, level-1);
  }
  
  Color refractive(0.0,0.0,0.0);
  if ((level>0)
      && (txt->kt().intensity()>0.01)) {
    real eta;
    if (r.in()) {
      eta = 1.0/txt->ior();
    } else {
      eta = txt->ior();
    }
    real ci;
    if (r.in()) {
      ci = (r.getDir().dot(-1.0*isect.normal()));
    } else {
      ci = (r.getDir().dot(isect.normal()));
    }
    real costt = 1.0 - (eta*eta) * (1.0-ci*ci);
  
    if (costt<0.0) {
      refractive = Color(0,0,0);
    } else {
      ++refractive_rays_cast;
      Ray tempRay(r.pointOn(isect.t()+eps),
		  ((eta*ci-std::sqrt(costt))*((r.in()?-1.0:1.0)*isect.normal())
		   - (eta*r.getDir())),
		  !r.in());
      refractive = shade(rtrace(tempRay, isect.object()), tempRay, level-1);

    }
  }

  curColor +=
    txt->ka()
    + (txt->kd()*diffuse
       + txt->ks()*specular
       + txt->kr()*reflective
       + txt->kt()*refractive)
    * shadowAmt;

  return curColor.clamp();
}

int Scene::getNumLights() {
  return lights.size();
}

int Scene::getNumObjects() {
  return objects.size();
}

void Scene::addLight(Light *lght) {
  size_t x_idx, y_idx, z_idx;
  lights.insert(lght);
  getIdxOfPoint(lght->location().x(),
		lght->location().y(),
		lght->location().z(),
		x_idx, y_idx, z_idx);
  theGrid[x_idx][y_idx][z_idx]->addLight(lght);
}
Camera Scene::getCamera() {
  return cam;
}
ObjectList &Scene::getObjects() {
  return objects;
}
LightList &Scene::getLights() {
  return lights;
}
unsigned int Scene::getNumRaysCast() {
  return rays_cast;
}

unsigned int Scene::getNumIntersectionTests() {
  return intersection_tests;
}

unsigned int Scene::getNumIntersections() {
  return intersections;
}

unsigned int Scene::getNumShadowRaysCast() {
  return shadow_rays_cast;
}

unsigned int Scene::getNumReflectiveRaysCast() {
  return reflective_rays_cast;
}

unsigned int Scene::getNumRefractiveRaysCast() {
  return refractive_rays_cast;
}


void Scene::trace(Image &img, real x1, real y1, real x2, real y2, int lev) {

  Vector zAxis = cam.getDirection().normal()*cam.getImagePlaneDistance();
  Vector yAxis = cam.getUp().normal();
  Vector xAxis = zAxis.cross(yAxis).normal();
  
  real xwidth = (x2-x1)/(img.getWidth()-1);
  real ywidth = (y2-y1)/(img.getHeight()-1);
  
  for (int i = 0;i<img.getWidth(); ++i) {
    Vector xVect = xAxis*(i*xwidth+x1);
    for (int j = 0;j<img.getHeight(); ++j) {
      Ray tempRay = Ray(
			cam.getLocation(),
			Vector(
			       xVect
			       + yAxis*((img.getHeight()-j)*ywidth+y1)
			       + zAxis).normal());
      img(i,j) = shade(rtrace(tempRay), tempRay, lev);
    }
  }
}
