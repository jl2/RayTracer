#include <iostream>
#include <cmath>
#include "sphere.h"

Sphere::Sphere(Point c, real r, Texture *txt) : Object(txt),
						center(c),
						radius(r) {}
void Sphere::getExtents(real &xmin, real &xmax,
			real &ymin, real &ymax,
			real &zmin, real &zmax) {
  xmin = center.x()-(radius);
  xmax = center.x()+(radius);
  ymin = center.y()-(radius);
  ymax = center.y()+(radius);
  zmin = center.z()-(radius);
  zmax = center.z()+(radius);
}

Intersection Sphere::intersect(Ray r, bool calcNorm) {
  Vector l = center-r.getOrigin();
  real d = l.dot(r.getDir());
  real lSquared = l.dot(l);

  if ((d <0.0) && (lSquared>(radius*radius))){
    return Intersection(0.0, false);
  }
  real mSquared = lSquared-(d*d);
  if (mSquared>(radius*radius)) {
    return Intersection(0.0, false);
  }
  real q = std::sqrt(radius*radius - mSquared);
  real t;
  if (lSquared > (radius*radius)) {
    t = d-q;
  } else {
    t = d+q;
  }
  if (calcNorm)
    return Intersection(t, true, this, (r.pointOn(t)-center).normal());
  return Intersection(t, true, this);
}

void Sphere::show() {
  std::cout << "Sphere:\n";
  std::cout << "Center at: ("
	    << center.x() << ", " << center.y()
	    << ", " << center.z() << ")\n";
  
  std::cout << "Radius: " << radius << '\n';
}
Sphere::~Sphere() {
}
