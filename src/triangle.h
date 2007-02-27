// triangle.h - Triangle class declaration

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

#ifndef RAY_TRACE_TRIANGLE_H
#define RAY_TRACE_TRIANGLE_H

#include "globaldefs.h"
#include "object.h"
#include "point.h"
#include "ray.h"
#include "intersection.h"

class Triangle : public Object {
 public:
  Triangle(Point p1, Point p2, Point p3, Texture *txt=0, bool fn=false);
  virtual Intersection intersect(Ray r, bool calcNorm=false);
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax);
  virtual ~Triangle();
 private:
  Point pt1;
  Point pt2;
  Point pt3;
  bool flipNorm;
};

#endif
