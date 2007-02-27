// sphere.h - Sphere class declaration

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

#ifndef RAY_TRACE_SPHERE_H
#define RAY_TRACE_SPHERE_H

#include "globaldefs.h"
#include "object.h"
#include "point.h"
#include "intersection.h"
#include "ray.h"

class Sphere : public Object {
public:
  Sphere(Point c, real r, Texture *txt=0);
  virtual Intersection intersect(Ray r, bool calcNorm=false);
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax);
  virtual void show();
  virtual ~Sphere();
private:
  Point center;
  real radius;
};

#endif
