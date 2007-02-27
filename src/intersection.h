#ifndef RAY_TRACE_INTERSECTION_H
#define RAY_TRACE_INTERSECTION_H

#include "globaldefs.h"

#include "vector.h"

class Object;

class GridEntry;

class Intersection {
 public:
  Intersection(real t=0.0, bool h=false,
	       Object *object=0, Vector normal= Vector(0.0,0.0,0.0));
  real &t();
  bool hits();
  Object *object();
  const Vector &normal();
  GridEntry *getGridEntry();
  void setGridEntry(GridEntry *ge);
 private:
  real tVal;
  bool hits_obj;
  Object *obj;
  Vector norm;
  GridEntry *gridCell;
};

#endif
