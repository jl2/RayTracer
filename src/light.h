#ifndef RAY_TRACE_LIGHT_H
#define RAY_TRACE_LIGHT_H

#include "globaldefs.h"
#include "color.h"
#include "point.h"
#include "ray.h"

class Light {
 public:
  Light(Point location, Color intense);
  Color &intensity();
  Ray getRayTo(Point from);
  Point &location();
  void show();
 private:
  Point loc;
  Color intense;
};

#endif
