#ifndef RAY_TRACE_GRID_ENTRY_H
#define RAY_TRACE_GRID_ENTRY_H

class GridEntry {
 public:
  GridEntry();
  ~GridEntry();
  void addObject(Object *obj);
  void addLight(Light *lght);
  Intersection intersect(Ray r, bool computeNormal, unsigned int *int_test,
			 unsigned int *int_hit);
  int getNumObjs();
 private:
  ObjectList objects;
  LightList lights;
  int objCount;
};

#endif
