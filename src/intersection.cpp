#include "intersection.h"

Intersection::Intersection(real t, bool h, Object *object, Vector normal) : tVal(t),
							     hits_obj(h),
							     obj(object),
							     norm(normal) {}

real &Intersection::t() {
  return tVal;
}
bool Intersection::hits() {
  return hits_obj;
}
Object *Intersection::object() {
  return obj;
}
const Vector &Intersection::normal() {
  return norm;
}
GridEntry *Intersection::getGridEntry() {
  return gridCell;
}
void Intersection::setGridEntry(GridEntry *ge) {
  gridCell = ge;
}
