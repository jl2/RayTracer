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
