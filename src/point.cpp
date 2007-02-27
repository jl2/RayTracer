// point.cpp - Implementation of Point class

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

#include "point.h"

Point::Point(real x, real y, real z) : xx(x), yy(y), zz(z) {}

real &Point::x() {
  return xx;
}
real &Point::y() {
  return yy;
}
real &Point::z() {
  return zz;
}
bool Point::operator==(const Point &p) {
  return ((xx==p.xx) &&
	  (yy==p.yy) &&
	  (zz==p.zz));
}
Point Point::operator+(Vector v) {
  return Point(xx+v.i(),
	       yy+v.j(),
	       zz+v.k());
}
Point Point::operator+=(Vector v) {
  xx+=v.i();
  yy+=v.j();
  zz+=v.k();
  return *this;
}
Vector Point::operator-(const Point &p) {
  return Vector(xx-p.xx, yy-p.yy, zz-p.zz);
}
