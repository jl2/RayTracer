// color.cpp - Implementation of Color class

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
#include "color.h"

Color::Color(real r, real g, real b, real a) {
  color[RED]=r;
  color[GREEN]=g;
  color[BLUE]=b;
  color[ALPHA]=a;
}
real &Color::operator[](int idx) {
  return color[idx];
}
real &Color::red() {
  return color[RED];
}
const real Color::getRed() {
  return color[RED];
}
real &Color::green() {
  return color[GREEN];
}
const real Color::getGreen() {
  return color[GREEN];
}
real &Color::blue() {
  return color[BLUE];
}
const real Color::getBlue() {
  return color[BLUE];
}
real &Color::alpha() {
  return color[ALPHA];
}
const real Color::getAlpha() {
  return color[ALPHA];
}
bool Color::operator==(const Color &col) {
  return ((col.color[RED]  == color[RED]) &&
	  (col.color[GREEN]== color[GREEN]) &&
	  (col.color[BLUE] == color[BLUE]) &&
	  (col.color[ALPHA]== color[ALPHA]));
}
Color Color::operator*(const Color &col) {
  return Color(color[RED]*col.color[RED],
	       color[GREEN]*col.color[GREEN],
	       color[BLUE]*col.color[BLUE],
	       color[ALPHA]*col.color[ALPHA]);
}

Color Color::operator*(real scale) {
  return Color(color[RED]*scale,
	       color[GREEN]*scale,
	       color[BLUE]*scale,
	       color[ALPHA]*scale);
}
Color Color::operator*=(real scale) {
  color[RED]*=scale;
  color[GREEN]*=scale;
  color[BLUE]*=scale;
  color[ALPHA]*=scale;
  return Color(color[RED],
	       color[GREEN],
	       color[BLUE],
	       color[ALPHA]);
}
Color Color::operator+=(const Color &col) {
  color[RED]+=col.color[RED];
  color[GREEN]+=col.color[GREEN];
  color[BLUE]+=col.color[BLUE];
  color[ALPHA]+=col.color[ALPHA];
  return Color(color[RED],
	       color[GREEN],
	       color[BLUE],
	       color[ALPHA]);
}
Color Color::operator+(const Color &col) {
  return Color(color[RED]+col.color[RED],
	       color[GREEN]+col.color[GREEN],
	       color[BLUE]+col.color[BLUE],
	       color[ALPHA]+col.color[ALPHA]);
}
Color Color::operator-=(const Color &col) {
  color[RED]-=col.color[RED];
  color[GREEN]-=col.color[GREEN];
  color[BLUE]-=col.color[BLUE];
  color[ALPHA]-=col.color[ALPHA];
  return Color(color[RED],
	       color[GREEN],
	       color[BLUE],
	       color[ALPHA]);
}
Color Color::operator-(const Color &col) {
  return Color(color[RED]-col.color[RED],
	       color[GREEN]-col.color[GREEN],
	       color[BLUE]-col.color[BLUE],
	       color[ALPHA]-col.color[ALPHA]);
}
Color Color::clamp() {
  return Color((color[RED]>1.0)?1.0:((color[RED]<0.0)?0.0:color[RED]),
	       (color[GREEN]>1.0)?1.0:((color[GREEN]<0.0)?0.0:color[GREEN]),
	       (color[BLUE]>1.0)?1.0:((color[BLUE]<0.0)?0.0:color[BLUE]),
	       (color[ALPHA]>1.0)?1.0:((color[ALPHA]<0.0)?0.0:color[ALPHA]));
}
real Color::intensity() {
  return std::sqrt(color[RED]*color[RED] +
		   color[GREEN]*color[GREEN] +
		   color[BLUE]*color[BLUE]);
}
