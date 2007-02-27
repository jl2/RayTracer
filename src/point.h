#ifndef RAY_TRACE_POINT_H
#define RAY_TRACE_POINT_H

#include "globaldefs.h"
#include "vector.h"

class Point {
 public:
  Point(real x=0.0, real y=0.0, real z=0.0);
  real &x();
  real &y();
  real &z();
  bool operator==(const Point &p);
  Point operator+(Vector v);
  Point operator+=(Vector v);
  Vector operator-(const Point &p);
 private:
  real xx, yy, zz;
};

#endif
