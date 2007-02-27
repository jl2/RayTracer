// color.h - Color class declaration

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

#ifndef RAY_TRACE_COLOR_H
#define RAY_TRACE_COLOR_H

#include "globaldefs.h"

// Color is used to store a color
class Color {
 public:
  Color(real r=0.0, real g=0.0, real b=0.0, real a=0.0);
  real &operator[](int idx);
  real &red();
  const real getRed();
  real &green();
  const real getGreen();
  real &blue();
  const real getBlue();
  real &alpha();
  const real getAlpha();
  bool operator==(const Color &col);
  Color operator*(const Color &col);
  Color operator*(real scale);
  Color operator*=(real scale);
  Color operator+=(const Color &col);
  Color operator+(const Color &col);
  Color operator-=(const Color &col);
  Color operator-(const Color &col);
  Color clamp();
  real intensity();
 private:
  static const int RED=0;
  static const int GREEN=1;
  static const int BLUE=2;
  static const int ALPHA=3;
  static const int NUM_CHANNELS=4;

  real color[NUM_CHANNELS];
};

#endif
