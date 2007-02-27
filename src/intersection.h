// intersection.h - Intersection class declaration

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

#ifndef RAY_TRACE_INTERSECTION_H
#define RAY_TRACE_INTERSECTION_H

#include "globaldefs.h"

#include "vector.h"

class Object;

class GridEntry;

class Intersection {
 public:
  Intersection(real t=0.0, bool h=false,
	       Object *object=0, Vector normal= Vector(0.0,0.0,0.0));
  real &t();
  bool hits();
  Object *object();
  const Vector &normal();
  GridEntry *getGridEntry();
  void setGridEntry(GridEntry *ge);
 private:
  real tVal;
  bool hits_obj;
  Object *obj;
  Vector norm;
  GridEntry *gridCell;
};

#endif
