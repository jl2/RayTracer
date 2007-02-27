// point.h - Point class declaration

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

#ifndef RAY_TRACE_POINT_H
#define RAY_TRACE_POINT_H

#include "globaldefs.h"
#include "vector.h"

class Point {
 public:
  Point(real x=0.0, real y=0.0, real z=0.0);
  real &x();
  real &y();
  real &z();
  bool operator==(const Point &p);
  Point operator+(Vector v);
  Point operator+=(Vector v);
  Vector operator-(const Point &p);
 private:
  real xx, yy, zz;
};

#endif
