#ifndef RAY_TRACE_SPHERE_H
#define RAY_TRACE_SPHERE_H

#include "globaldefs.h"
#include "object.h"
#include "point.h"
#include "intersection.h"
#include "ray.h"

class Sphere : public Object {
public:
  Sphere(Point c, real r, Texture *txt=0);
  virtual Intersection intersect(Ray r, bool calcNorm=false);
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax);
  virtual void show();
  virtual ~Sphere();
private:
  Point center;
  real radius;
};

#endif
