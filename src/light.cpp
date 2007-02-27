// light.cpp - Implementation of the Light class

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

#include "light.h"

Light::Light(Point location, Color intensity) : loc(location), intense(intensity) {}

Ray Light::getRayTo(Point from) {
  return Ray(from, (loc-from).normal());
}

Color &Light::intensity() {
  return intense;
}

Point &Light::location() {
  return loc;
}

void Light::show() {
}
