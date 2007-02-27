// image.h - Image class declarations

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

#ifndef RAY_TRACE_IMAGE_H
#define RAY_TRACE_IMAGE_H

#include <ostream>
#include "globaldefs.h"
#include "color.h"

// The Image class stores an array of colors that represent an image.
class Image {
 public:
  Image(int w, int h);
  ~Image();
  Color &operator()(int x, int y);
  Color &getPixel(int x, int y);    
  int getHeight();
  int getWidth();
  void toPPM(std::ostream &out);
 private:
  Color *image;
  int width, height;
};

#endif
