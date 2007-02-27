// vector.cpp - Implementation of the Vector class

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

#include <cmath>
#include "vector.h"

Vector::Vector(real i, real j, real k) : ii(i), jj(j), kk(k) {
}
real &Vector::i() {
  return ii;
}
real &Vector::j() {
  return jj;
}
real &Vector::k() {
  return kk;
}
bool Vector::operator==(Vector v) {
  return ((ii==v.ii) &&
	  (jj==v.jj) &&
	  (kk==v.kk));
}
Vector Vector::operator+(Vector v) {
  return Vector(v.ii+ii,
		v.jj+jj,
		v.kk+kk);
}
Vector Vector::operator+=(Vector v) {
  ii+=v.ii;
  jj+=v.jj;
  kk+=v.kk;
  return *this;
}
Vector Vector::operator-(Vector v) {
  return Vector(ii-v.ii,
		jj-v.jj,
		kk-v.kk);
}
Vector Vector::operator-=(Vector v) {
  ii-=v.ii;
  jj-=v.jj;
  kk-=v.kk;
  return *this;
}
// TODO: add a friend function to allow 2.0*vector
// Currently only works for vector*2.0
Vector Vector::operator*(real s) {
  return Vector(s*ii, s*jj, s*kk);
}
Vector operator*(real s, Vector v) {
  return v*s;
}
Vector Vector::operator*=(real s) {
  ii*=s;
  jj*=s;
  kk*=s;
  return *this;
}
const real Vector::length() {
  return (std::sqrt(ii*ii+jj*jj+kk*kk));
}
real Vector::dot(Vector v) {
  return (v.ii*ii + v.jj*jj + v.kk*kk);
}
Vector Vector::cross(Vector v) {
  return Vector(jj*v.kk-kk*v.jj,
		kk*v.ii-ii*v.kk,
		ii*v.jj-jj*v.ii);
}
Vector Vector::normal() {
  if (length()==0.0) return *this;
  return operator*(1.0/length());
}

