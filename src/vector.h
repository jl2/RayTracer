// vector.h - Vector class declaration

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

#ifndef RAY_TRACE_VECTOR_H
#define RAY_TRACE_VECTOR_H

#include "globaldefs.h"

class Vector {
 public:
  Vector(real i=0.0, real j=0.0, real k=0.0);
  real &i();
  real &j();
  real &k();
  bool operator==(Vector v);
  bool operator!=(Vector v) { return !(*this==v); };
  Vector operator+(Vector v);
  Vector operator+=(Vector v);
  Vector operator-(Vector v);
  Vector operator-=(Vector v);
  // TODO: add a friend function to allow 2.0*vector
  // Currently only works for vector*2.0
  Vector operator*(real s);
  Vector operator*=(real s);
  const real length();
  real dot(Vector v);
  Vector cross(Vector v);
  Vector normal();
 private:
  real ii, jj, kk;
};

Vector operator*(real s, Vector v);

#endif
