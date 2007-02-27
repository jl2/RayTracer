// ray.cpp - Implementation of the Ray class

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

#include "ray.h"

Ray::Ray(Point o, Vector d, bool in) : dir(d), orig(o), isIn(in)  {
}
Vector Ray::getDir() {
  return dir;
}
Point Ray::getOrigin() {
  return orig;
}
Point Ray::pointOn(real t) {
  return orig+dir*t;
}
bool Ray::in() {
  return isIn;
}
