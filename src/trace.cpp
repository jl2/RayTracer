/* trace.cpp - Main driver for ray tracer */

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

#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#include "globaldefs.h"
#include "color.h"
#include "image.h"
#include "vector.h"
#include "ray.h"
#include "intersection.h"
#include "object.h"
#include "sphere.h"
#include "triangle.h"
#include "texture.h"
#include "light.h"
#include "camera.h"
#include "scene.h"

real x(real u, real v) {
  return u;
  //  return 3+sin(u)*(7 - cos(3*u-2*v) - 2*cos(3*u+v));
    //sin(u)*(7+cos(u/3.0 - 2.0*v) + 2*cos(u/3.0 + v));
}
real y(real u, real v) {
  return v;
  //return 3+cos(u)*(7 - cos(3*u-2*v) - 2*cos(3*u+v));
    // cos(u)*(7+cos(u/3.0 - 2.0*v) + 2*cos(u/3.0 + v));;
}

real z(real u, real v) {
  return 0.0; //2.5*sin(u)*cos(v);
  //  return sin(3*u-2*v) + 2*sin(3*u+v);
    // sin(u/3.0 - 2*v) + 2*sin(u/3.0 + v);
}

int main(int argc, char *argv[]) {

  if (argc<2) {
    std::cerr << "Syntax is:\n\t" << argv[0] << " filename\n";
    exit(1);
  }
  
  Image img(360,360);

  Scene scn(Camera(Point(15,15,15),
		   Point(0.0,0.0,0.0),
		   1.0,
		   Vector(0.0,1.0,0.0)),
	    Color(0.0,0.0,0.0),
	    -16.0,16.0,
	    -16.0,16.0,
	    -16.0,16.0,
	    30,30,30);

  Texture *textArray[] = {
    new Texture (Color(0.75,0.75,0.75),
		 Color(0.0,0.0,0.0),
		 Color(0.0,0.0,0.0),
		 20,
		 Color(0.0,0.0,0.0)),
    
    new Texture (Color(0.0,0.0,1.0),
		 Color(0.0,0.1,0.0),
		 Color(1.0,1.0,1.0),
		 90,
		 Color(0,0,0)),
    
    new Texture (Color(0.25,0.25,0.0),
		 Color(0.0,0.0,0.0),
		 Color(1.0,1.0,1.0),
		 100,
		 Color(0.25,0.25,0.25),
		 Color(0.5,0.5,0.5),
		 0.85),
    
    new Texture (Color(0.0,1.0,0.0),
		 Color(0.0,0.0,0.0),
		 Color(1.0,1.0,1.0),
		 200,
		 Color(0.0,0.0,0.0))};

  const real PI = 3.141592654;
  real umin = -15;
  real umax = 15;
  real vmin = -15;
  real vmax = 15;
  /*
  int usteps = 1;
  int vsteps = 1;
  real umult = (umax-umin)/(usteps-1);
  real vmult = (vmax-vmin)/(vsteps-1);
  real uval, vval;
  for (int i=0;i<usteps;++i) {
    uval = i*umult + umin;
    for (int j=0;j<vsteps; ++j) {
      vval = j*vmult + vmin;
      scn.addObject(new Triangle(Point(
				       x(uval,vval),
				       y(uval,vval),
				       z(uval,vval)),
				 Point(
				       x(uval+umult,vval),
				       y(uval+umult,vval),
				       z(uval+umult,vval)),
				 Point(
				       x(uval,vval+vmult),
				       y(uval,vval+vmult),
				       z(uval,vval+vmult)),
				 textArray[3]));
      scn.addObject(new Triangle(Point(
				       x(uval+umult,vval+vmult),
				       y(uval+umult,vval+vmult),
				       z(uval+umult,vval+vmult)),
				 Point(
				       x(uval+umult,vval),
				       y(uval+umult,vval),
				       z(uval+umult,vval)),
				 Point(
				       x(uval,vval+vmult),
				       y(uval,vval+vmult),
				       z(uval,vval+vmult)),
				 textArray[3],
				 true));
    }
  }
  */

  /*
  const real PI = 3.141592654;
  real umin = -15;
  real umax = 15;
  real vmin = -15;
  real vmax = 15;

  int usteps = 64;
  int vsteps = 64;
  real umult = (umax-umin)/(usteps-1);
  real vmult = (vmax-vmin)/(vsteps-1);
  real uval, vval;
  for (int i=0;i<usteps;++i) {
    uval = i*umult + umin;
    for (int j=0;j<vsteps; ++j) {
      vval = j*vmult + vmin;
      scn.addObject(new Sphere(Point(
				     x(uval,vval),
				     y(uval,vval),
				     z(uval,vval)),
			       umult,
			       textArray[3]));

    }
  }
  */


  scn.addObject(new Sphere(Point(7.5,7.5,7.5), 2.5, textArray[2]));

  for (int i=1;i<= 14; ++i) {
    for (int j = 1; j<= 14; ++j) {
      scn.addObject(new Sphere(Point(i, j, 0),
			       0.5,
			       textArray[3]));
      scn.addObject(new Sphere(Point(0, i, j),
			       0.5,
			       textArray[3]));
      scn.addObject(new Sphere(Point(j, 0, i),
			       0.5,
			       textArray[3]));
    }
  }


  /*
  scn.addObject(new Sphere(Point(0,1.5,2.5),  2.5, textArray[2]));
  scn.addObject(new Sphere(Point(0,0,-2.5), 2.5, textArray[3]));
  scn.addObject(new Sphere(Point(-3.75,2.5,1.25), 1.25, textArray[1]));
  */
  /*
  scn.addObject(new Triangle(Point(8, 8, 0),
			     Point(8, -8, 0),
			     Point(-8, 8, 0),
			     textArray[0],
			     true));
  scn.addObject(new Triangle(Point(-8, -8, 0),
			     Point(8, -8, 0),
			     Point(-8, 8, 0),
			     textArray[0],
			     false));

  scn.addObject(new Triangle(Point(0, 8, 8),
			     Point(0, -8, 8),
			     Point(0, 8, -8),
			     textArray[0],
			     false));
  scn.addObject(new Triangle(Point(0, -8, -8),
			     Point(0, -8, 8),
			     Point(0, 8, -8),
			     textArray[0],
			     true));
  */
  //  scn.addLight(new Light(Point(10,10,10), Color(1.0,1.0,1.0)));
  //  scn.addLight(new Light(Point(10,10,-10), Color(1.0,1.0,1.0)));
  scn.addLight(new Light(Point(15,15,15), Color(1.0,1.0,1.0)));


  real mean, var, stdDev;
  int min, max;
  real meanCells, varCells, stdDevCells;
  int minCells;
  int maxCells;
  scn.getGridStats(mean, stdDev, var, min, max,
		   meanCells, stdDevCells,
		   varCells, minCells, maxCells);
  std::cout << "Scene stats:\n"
	    << "Number of objects     : " << scn.getNumObjects() << "\n"
	    << "Number of lights      : " << scn.getNumLights() << "\n"
	    << "Number of cells       : " << scn.getNumCells() << "\n"
	    << "Grid stats:\n"
	    << "Mean objects per cell : " << mean << "\n"
	    << "Std. deviation        : " << stdDev << "\n"
	    << "Variance              : " << var << "\n"
	    << "Minimum               : " << min << "\n"
	    << "Maximum               : " << max << "\n"
	    << "Object stats:\n"
	    << "Mean cells per object : " << meanCells << "\n"
	    << "Std. Deviation        : " << stdDevCells << "\n"
	    << "Variance              : " << varCells <<"\n"
	    << "Min cells per object  : " << minCells << "\n"
	    << "Max cells per object  : " << maxCells << "\n";
   
  scn.trace(img, -1.0, -1.0, 1.0, 1.0, 9);

  std::ofstream outf(argv[1]);
  img.toPPM(outf);
  outf.close();

  std::cout << "Rays cast: " << scn.getNumRaysCast() << "\n"
	    << "Intersection tests: "
	    << scn.getNumIntersectionTests() << "\n"
	    << "Intersections: "
	    << scn.getNumIntersections() << "\n"
	    << "Shadow rays cast: "
	    << scn.getNumShadowRaysCast() << "\n"
	    << "Reflective rays cast: "
	    << scn.getNumReflectiveRaysCast() << "\n"
	    << "Refractive rays cast: "
	    << scn.getNumRefractiveRaysCast() << "\n";

  return 0;
}
