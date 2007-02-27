// camera.h - Camera class declarations

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

#ifndef RAY_TRACE_CAMERA_H
#define RAY_TRACE_CAMERA_H

#include "globaldefs.h"
#include "point.h"
#include "vector.h"


//! A normal member taking two arguments and returning an integer value.
/*!
  \param a an integer argument.
  \param s a constant character pointer.
  \return The test results
  \sa Test(), ~Test(), testMeToo() and publicVar()
*/
//!  A test class. 
/*!
  A more elaborate class description.
*/

class Camera {
 public:
  Camera();
  Camera(Point location, Vector direction,
	 real distance=1.0, Vector up=Vector(0.0,0.0,1.0));
  Camera(Point location, Point lookAt, real distance=1.0,
	 Vector up=Vector(0.0,1.0,0.0));
  void setupCamera(Point location, Point lookAt, Vector up);    
  real getImagePlaneDistance();
  void setImagePlaneDistance(real distance);
  Point getLocation();
  void setLocation(Point location);
  Vector getDirection();
  void setDirection(Vector direction);
  Vector getUp();
  void setUp(Vector up);    
 private:
  Point loc;
  Vector dir;
  real dist;
  Vector upv;
};

#endif
