/*
  Put licensing stuff here...
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
