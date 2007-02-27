#ifndef RAY_TRACE_OBJECT_H
#define RAY_TRACE_OBJECT_H

#include "globaldefs.h"
#include "ray.h"
#include "intersection.h"
#include "texture.h"
#include "vector.h"
#include "point.h"

class Object {
 public:
  Object(Texture *txt=0);
  virtual Intersection intersect(Ray r, bool calcNorm=false)=0;
  virtual void show()=0;
  virtual void getExtents(real &xmin, real &xmax,
			  real &ymin, real &ymax,
			  real &zmin, real &zmax) = 0;
  virtual ~Object() {}
  Texture *getTexture();
  void setTexture(Texture *text);
  int getNumCells();
  void incCellCount();
 protected:
  Texture *txt;
  int numCells;
 private:
};

#endif
