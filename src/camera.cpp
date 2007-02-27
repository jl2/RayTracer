#include "camera.h"

Camera::Camera() {
  loc = Point(0.0,0.0,0.0);
  dir = Vector(0.0,1.0,0.0);
  dist = 1.0;
  upv = Vector(0.0,0.0,1.0);
}
Camera::Camera(Point location, Vector direction,
       real distance, Vector up)
  : loc(location),
    dir(direction.normal()),
    dist(distance),
    upv(up) {}

Camera::Camera(Point location, Point lookAt, real distance,
	       Vector up) : loc(location),
			    dir(Vector(lookAt.x()-location.x(),
				       lookAt.y()-location.y(),
				       lookAt.z()-location.z()).normal()),
			    dist(distance),
			    upv(dir.cross(up).cross(dir)) {}

void Camera::setupCamera(Point location, Point lookAt, Vector up) {
  loc = location;
  dir = Vector(location.x()-lookAt.x(),
	       location.y()-lookAt.y(),
	       location.y()-lookAt.z()).normal();
  dist = 1.0;
  upv = up;
}
    
real Camera::getImagePlaneDistance() {
  return dist;
}
void Camera::setImagePlaneDistance(real distance) {
  dist = distance;
}
Point Camera::getLocation() {
  return loc;
}
void Camera::setLocation(Point location) {
  loc = location;
}
Vector Camera::getDirection() {
  return dir;
}
void Camera::setDirection(Vector direction) {
  dir = direction;
}
Vector Camera::getUp() {
  return upv;
}
void Camera::setUp(Vector up) {
  upv = up;
}
