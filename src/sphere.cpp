// sphere.cpp - Implementation of the Sphere class

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
