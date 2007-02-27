// camera.cpp - Implementation of the camera class

/*
  Copyright (C) 2007 Jeremiah LaRocco

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

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
