#include "point.h"

Point::Point(real x, real y, real z) : xx(x), yy(y), zz(z) {}

real &Point::x() {
  return xx;
}
real &Point::y() {
  return yy;
}
real &Point::z() {
  return zz;
}
bool Point::operator==(const Point &p) {
  return ((xx==p.xx) &&
	  (yy==p.yy) &&
	  (zz==p.zz));
}
Point Point::operator+(Vector v) {
  return Point(xx+v.i(),
	       yy+v.j(),
	       zz+v.k());
}
Point Point::operator+=(Vector v) {
  xx+=v.i();
  yy+=v.j();
  zz+=v.k();
  return *this;
}
Vector Point::operator-(const Point &p) {
  return Vector(xx-p.xx, yy-p.yy, zz-p.zz);
}
