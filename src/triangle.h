#ifndef RAY_TRACE_TRIANGLE_H
#define RAY_TRACE_TRIANGLE_H

#include "globaldefs.h"
#include "object.h"
#include "point.h"
#include "ray.h"
#include "intersection.h"

class Triangle : public Object {
 public:
  Triangle(Point p1, Point p2, Point p3, Texture *txt=0, bool fn=false);
  virtual Intersection intersect(Ray r, bool calcNorm=false);
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax);
  virtual void show();
  virtual ~Triangle();
 private:
  Point pt1;
  Point pt2;
  Point pt3;
  bool flipNorm;
};

#endif
