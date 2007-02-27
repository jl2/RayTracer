#include <iostream>
#include "triangle.h"

Triangle::Triangle(Point p1, Point p2, Point p3, Texture *txt, bool fn)
  : Object(txt), pt1(p1), pt2(p2), pt3(p3), flipNorm(fn) {
}

void Triangle::getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax) {
  xmin =
    ((pt1.x()<pt2.x()) ?
     ((pt1.x()<pt3.x()) ? pt1.x() : pt3.x())
     : ((pt2.x()<pt3.x()) ? pt2.x() : pt3.x()));
  xmax =
     ((pt1.x()>pt2.x()) ?
     ((pt1.x()>pt3.x()) ? pt1.x() : pt3.x())
      : ((pt2.x()>pt3.x()) ? pt2.x() : pt3.x()));
  ymin =
    ((pt1.y()<pt2.y()) ?
     ((pt1.y()<pt3.y()) ? pt1.y() : pt3.y())
     : ((pt2.y()<pt3.y()) ? pt2.y() : pt3.y()));
  ymax =
     ((pt1.y()>pt2.y()) ?
     ((pt1.y()>pt3.y()) ? pt1.y() : pt3.y())
      : ((pt2.y()>pt3.y()) ? pt2.y() : pt3.y()));
  zmin =
    ((pt1.z()<pt2.z()) ?
     ((pt1.z()<pt3.z()) ? pt1.z() : pt3.z())
     : ((pt2.z()<pt3.z()) ? pt2.z() : pt3.z()));
  zmax =
     ((pt1.z()>pt2.z()) ?
     ((pt1.z()>pt3.z()) ? pt1.z() : pt3.z())
      : ((pt2.z()>pt3.z()) ? pt2.z() : pt3.z()));
}

Intersection Triangle::intersect(Ray r, bool calcNorm) {
  const real eps = 0.0001;
  Vector e1(pt2-pt1);
  Vector e2(pt3-pt1);
  Vector p(r.getDir().cross(e2));
  real a = e1.dot(p);
  if ((a > -eps) && (a < eps)) {
    return Intersection(0.0, false);
  }
  real f = 1.0/a;
  Vector s = r.getOrigin()-pt1;
  real u = f*s.dot(p);
  if (u<0.0 || u>1.0) {
    return Intersection(0.0, false);
  }
  Vector q = s.cross(e1);
  real v = f*r.getDir().dot(q);
  if (v < 0.0 || (u+v)>1.0) {
    return Intersection(0.0, false);
  }
  if (calcNorm) {
    if (flipNorm) {
      return Intersection(f*e2.dot(q), true, this, (e2.cross(e1)).normal());
    } else {
      return Intersection(f*e2.dot(q), true, this, (e1.cross(e2)).normal());
    }
  }
  return Intersection(f*e2.dot(q), true, this);
}

void Triangle::show() {
  std::cout << "Triangle:\n";
  std::cout << "P1: ("
	    << pt1.x() << ", "
	    << pt1.y() << ", "
	    << pt1.z() << ")\n";
  std::cout << "P2: ("
	    << pt2.x() << ", "
	    << pt2.y() << ", "
	    << pt2.z() << ")\n";
  std::cout << "P3: ("
	    << pt3.x() << ", "
	    << pt3.y() << ", "
	    << pt3.z() << ")\n";
}
Triangle::~Triangle() {
}
