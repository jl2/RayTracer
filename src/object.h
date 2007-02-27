// object.h - Object abstract class declaration

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

#ifndef RAY_TRACE_OBJECT_H
#define RAY_TRACE_OBJECT_H

#include "globaldefs.h"
#include "ray.h"
#include "intersection.h"
#include "texture.h"
#include "vector.h"
#include "point.h"

class Object {
 public:
  Object(Texture *txt=0);
  virtual Intersection intersect(Ray r, bool calcNorm=false)=0;
  virtual void show()=0;
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax) = 0;
  virtual ~Object() {}
  Texture *getTexture();
  void setTexture(Texture *text);
  int getNumCells();
  void incCellCount();
 protected:
  Texture *txt;
  int numCells;
 private:
};

#endif
