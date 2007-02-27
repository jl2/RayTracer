#ifndef RAY_TRACE_SCENE_H
#define RAY_TRACE_SCENE_H

#include <set>
#include <vector>

#include "globaldefs.h"
#include "object.h"
#include "image.h"
#include "camera.h"
#include "color.h"
#include "light.h"

typedef std::set<Object*> ObjectList;
typedef std::set<Light*> LightList;

class GridEntry {
 public:
  GridEntry();
  ~GridEntry();
  void addObject(Object *obj);
  void addLight(Light *lght);
  Intersection intersect(Ray r, bool computeNormal, unsigned int *int_test,
			 unsigned int *int_hit);
  int getNumObjs();
 private:
  ObjectList objects;
  LightList lights;
  int objCount;
};

class Scene {
 public:
  Scene(Camera camera=Camera(Point(0.0,1.0,1.0),
			     Point(0.0,0.0,0.0),
			     1.0),
	Color bColor=Color(0.0,0.0,0.0),
	real xmin=-10.0, real xmax=10.0,
	real ymin=-10.0, real ymax=10.0,
	real zmin=-10.0, real zmax=10.0,
	size_t w=10, size_t h=10, size_t d=10);
  ~Scene();
  void addObject(Object *obj);
  void addLight(Light *lght);
  void trace(Image &img, real x1, real y1, real x2, real y2, int lev=4);
  Camera getCamera();
  ObjectList &getObjects();
  LightList &getLights();

  void getGridStats(real &mean, real &stdDeviation,
		    real &variance, int &min, int &max,
		    real &meanCells, real &stdDeviationCells,
		    real &varianceCells,
		    int &minCells, int &maxCells);
  int getNumCells();
  int getNumObjects();
  int getNumLights();
  unsigned int getNumRaysCast();
  unsigned int getNumIntersectionTests();
  unsigned int getNumIntersections();
  unsigned int getNumShadowRaysCast();
  unsigned int getNumReflectiveRaysCast();
  unsigned int getNumRefractiveRaysCast();
  
 private:
  Intersection rtrace(Ray r, bool computeNorm=true, Object *curObj = 0);
  Color shade(Intersection isect, Ray r, int level);

 private:
  void getIdxOfPoint(real x, real y, real z, size_t &xidx, size_t &yidx, size_t &zidx);
  
 private:
  typedef std::vector<GridEntry*> grid_row_t;
  typedef std::vector<grid_row_t> grid_plane_t;
  typedef std::vector<grid_plane_t> grid_t;
  grid_t theGrid;

  Camera cam;
  Color bgColor; 
  real x_min, x_max;
  real y_min, y_max;
  real z_min, z_max;
  size_t width, height, depth;
  
  ObjectList objects;
  LightList lights;

  // Statistics
  unsigned int rays_cast;
  unsigned int reflective_rays_cast;
  unsigned int refractive_rays_cast;
  unsigned int shadow_rays_cast;
  unsigned int intersections;
  unsigned int intersection_tests;
  
};

#endif
