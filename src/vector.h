#ifndef RAY_TRACE_VECTOR_H
#define RAY_TRACE_VECTOR_H

#include "globaldefs.h"

class Vector {
 public:
  Vector(real i=0.0, real j=0.0, real k=0.0);
  real &i();
  real &j();
  real &k();
  bool operator==(Vector v);
  Vector operator+(Vector v);
  Vector operator+=(Vector v);
  Vector operator-(Vector v);
  Vector operator-=(Vector v);
  // TODO: add a friend function to allow 2.0*vector
  // Currently only works for vector*2.0
  Vector operator*(real s);
  Vector operator*=(real s);
  const real length();
  real dot(Vector v);
  Vector cross(Vector v);
  Vector normal();
 private:
  real ii, jj, kk;
};

Vector operator*(real s, Vector v);

#endif
