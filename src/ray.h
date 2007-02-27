#ifndef RAY_TRACE_RAY_H
#define RAY_TRACE_RAY_H

#include "globaldefs.h"
#include "vector.h"
#include "point.h"

class Ray {
 public:
  Ray(Point o, Vector d, bool in=false);
  Vector getDir();
  Point getOrigin();
  Point pointOn(real t);
  bool in();
 private:
  Vector dir;
  Point orig;
  bool isIn;
};

#endif
