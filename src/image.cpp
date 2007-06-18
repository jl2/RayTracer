// image.cpp - Implementation of Image class

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

#include "image.h"

Image::Image(int w, int h) : width(w), height(h) {
  image = new Color[w*h];
}
Image::~Image() {
  delete [] image;
  width=0;
  height=0;
}
Color &Image::operator()(int x, int y) {
  return getPixel(x,y);
}
Color &Image::getPixel(int x, int y) {
    if ((x>height) || (y>width) ||
	(x<0) || (y<0)) {
	throw std::runtime_error("Invalid pixel");
    }
  return image[(y*width)+x];
}
    
int Image::getHeight() {
  return height;
}
int Image::getWidth() {
  return width;
}

void Image::toPPM(std::ostream &out) {
  out << "P3\n";
  out << width << " " << height << "\n";
  out << "255";
    for (int i = 0; i < width*height; ++i) {
      if (i % (70/13)==0)
	out << "\n";
      out << int(255*std::abs(image[i].red())) << " "
	  << int(255*std::abs(image[i].green())) << " "
	  << int(255*std::abs(image[i].blue())) << "  ";

  }
}
