#include "light.h"

Light::Light(Point location, Color intensity) : loc(location), intense(intensity) {}

Ray Light::getRayTo(Point from) {
  return Ray(from, (loc-from).normal());
}

Color &Light::intensity() {
  return intense;
}

Point &Light::location() {
  return loc;
}

void Light::show() {
}
