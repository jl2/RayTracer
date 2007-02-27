// texture.h - Texture class declaration

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

#ifndef RAY_TRACE_TEXTURE_H
#define RAY_TRACE_TEXTURE_H

#include "globaldefs.h"
#include "color.h"

class Texture {
public:
    Texture(Color kd=Color(0.0,0.0,0.0,0.0),
	    Color ka=Color(0.0,0.0,0.0,0.0),
	    Color ks=Color(0.0,0.0,0.0,0.0),
	    real n=12.0,
	    Color kr=Color(0.0,0.0,0.0,0.0),
	    Color kt=Color(0.0,0.0,0.0,0.0),
	    real ior=1.0);
    Color &kd();
    Color &ka();
    Color &ks();
    Color &kt();
    Color &kr();
    real &n();
    real &ior();
private:
    Color kdiffuse;
    Color kambient;
    Color kspecular;
    real specn;
    Color kreflect;
    Color ktrans;
    real indexOfRefraction;
};

#endif
