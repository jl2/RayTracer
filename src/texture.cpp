// texture.cpp - Implementation of the Texture class

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

#include "texture.h"

Texture::Texture(Color kd, Color ka,
		 Color ks, real n,
		 Color kr,
		 Color kt, real ior)
  : kdiffuse(kd),
    kambient(ka),
    kspecular(ks),
    specn(n),
    kreflect(kr),
    ktrans(kt),
    indexOfRefraction(ior) {}

Color &Texture::kd() {
  return kdiffuse;
}
Color &Texture::ka() {
  return kambient;
}
Color &Texture::ks() {
  return kspecular;
}
Color &Texture::kr() {
  return kreflect;
}
Color &Texture::kt() {
  return ktrans;
}
real &Texture::n() {
  return specn;
}
real &Texture::ior() {
  return indexOfRefraction;
}
