#include "ray.h"

Ray::Ray(Point o, Vector d, bool in) : dir(d), orig(o), isIn(in)  {
}
Vector Ray::getDir() {
  return dir;
}
Point Ray::getOrigin() {
  return orig;
}
Point Ray::pointOn(real t) {
  return orig+dir*t;
}
bool Ray::in() {
  return isIn;
}
