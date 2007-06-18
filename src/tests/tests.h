#include <cxxtest/TestSuite.h>
#include <cmath>

#include "point.h"
#include "vector.h"
#include "color.h"
#include "ray.h"
#include "camera.h"
#include "triangle.h"
#include "intersection.h"
#include "texture.h"
#include "sphere.h"
#include "light.h"
#include "image.h"
#include <sstream>
#include <string>

class TestSuite : public CxxTest::TestSuite {
 public:
  
  void setUp(void) {
  }
  
  void tearDown(void) {
  }
  
  void testPointVectorAddition(void) {

    Point p1(1.0,1.0,1.0);
    Vector v1(1.0,1.0,1.0);

    Point addTest=p1+v1;
    
    TS_ASSERT_EQUALS(addTest.x(), 2.0);
    TS_ASSERT_EQUALS(addTest.y(), 2.0);
    TS_ASSERT_EQUALS(addTest.z(), 2.0);
  }
  
  void testPointVectorPlusEquals(void) {

    Point p1(1.0,1.0,1.0);
    Vector v1(1.0,1.0,1.0);

    p1+=v1;
    
    TS_ASSERT_EQUALS(p1.x(), 2.0);
    TS_ASSERT_EQUALS(p1.y(), 2.0);
    TS_ASSERT_EQUALS(p1.z(), 2.0);
  }
  
  void testPointEquals(void) {

    Point p1(1.0,1.0,1.0);
    Point p2(1.0,1.0,1.0);

    TS_ASSERT_EQUALS(p1, p2);
  }
  
  void testPointMinus(void) {

    Point p1(1.0,1.0,1.0);
    Point p2(2.0,2.0,2.0);

    Vector result(1.0,1.0,1.0);
    TS_ASSERT_EQUALS(p2-p1, result);
  }

  void testVectorEqual(void) {
    Vector v1(1.0,2.0,3.0);
    Vector v2(1.0,2.0,3.0);
    Vector v3(3.0,2.0,1.0);
    
    TS_ASSERT_EQUALS(v1,v2);
    TS_ASSERT_EQUALS(v1.i(), 1.0);
    TS_ASSERT_EQUALS(v1.j(), 2.0);
    TS_ASSERT_EQUALS(v1.k(), 3.0);
    TS_ASSERT_EQUALS(v2,v1);
    TS_ASSERT_DIFFERS(v1,v3);
  }
  
  void testVectorScale(void) {
    Vector v1(1.0,2.0,3.0);
    Vector v2(2.0,4.0,6.0);

    TS_ASSERT_EQUALS(v1*2, v2);

    v1*=2.0;
    TS_ASSERT_EQUALS(v1, v2);
  }
  void testVectorLength(void) {
    Vector v1(0.0,0.0,0.0);
    Vector v2(1.0,0.0,0.0);
    Vector v3(0.0,1.0,0.0);
    Vector v4(0.0,0.0,1.0);
    Vector v5(1.0,1.0,1.0);
    Vector v6(2.0,1.0,0.0);
    Vector v7(0.0,1.0,2.0);
    
    TS_ASSERT_EQUALS(v1.length(), 0);
    TS_ASSERT_EQUALS(v2.length(), 1);
    TS_ASSERT_EQUALS(v3.length(), 1);
    TS_ASSERT_EQUALS(v4.length(), 1);
    TS_ASSERT_EQUALS(v5.length(), std::sqrt(3.0));
    TS_ASSERT_EQUALS(v6.length(), std::sqrt(5.0));
    TS_ASSERT_EQUALS(v7.length(), std::sqrt(5.0));
  }
  void testVectorNormal(void) {
    Vector v2(1.0,0.0,0.0);
    Vector v3(0.0,1.0,0.0);
    Vector v4(0.0,0.0,1.0);
    Vector v5(1.0,1.0,1.0);
    
    TS_ASSERT_EQUALS(v2.normal(), v2);
    TS_ASSERT_EQUALS(v3.normal(), v3);
    TS_ASSERT_EQUALS(v4.normal(), v4);
    TS_ASSERT_EQUALS(v5.normal(), Vector(std::sqrt(3.0)/3.0,
					 std::sqrt(3.0)/3.0,
					 std::sqrt(3.0)/3.0));
  }
  void testVectorDot(void) {
    Vector v1(1.0,1.0,1.0);
    Vector v2(0.0,1.0,0.0);

    Vector v3(1.0,2.0,3.0);

    TS_ASSERT_EQUALS(v1.dot(v2), 1.0);
    TS_ASSERT_EQUALS(v1.dot(v2), v2.dot(v1));
    
    TS_ASSERT_EQUALS(v1.dot(v3), 6.0);
    TS_ASSERT_EQUALS(v1.dot(v3), v3.dot(v1));
    
    TS_ASSERT_EQUALS(v2.dot(v3), 2.0);
    TS_ASSERT_EQUALS(v2.dot(v3), v3.dot(v2));
  }
  void testVectorCross(void) {
    Vector v1(1.0,1.0,1.0);
    Vector v2(1.0,2.0,3.0);
    Vector v3(0.0,1.0,0.0);
    Vector v4(1.0,0.0,1.0);

    TS_ASSERT_EQUALS(v1.cross(v2), Vector(1.0,-2.0,1.0));
    TS_ASSERT_EQUALS(v2.cross(v1), Vector(-1.0,2.0,-1.0));
    TS_ASSERT_EQUALS(v1.cross(v3), Vector(-1.0,0.0,1.0));
    TS_ASSERT_EQUALS(v3.cross(v4), Vector(1.0,0.0,-1.0));
    TS_ASSERT_EQUALS(v4.cross(v2), Vector(-2.0,-2.0,2.0));
  }
  void testColorScale(void) {
    Color c1(1.0,2.0,3.0);
    Color c2(2.0,4.0,6.0);

    TS_ASSERT_EQUALS(c1*2.0, c2);

    c1*=2.0;
    TS_ASSERT_EQUALS(c1, c2);
  }
  void testColorAddition(void) {
    Color c1(1.0,2.0,3.0);
    Color c2(2.0,4.0,6.0);

    TS_ASSERT_EQUALS(c1+c2, Color(3.0,6.0,9.0));
    
    c1+=c1;
    TS_ASSERT_EQUALS(c1,c2);
  }
  void testColorSubtraction(void) {
    Color c1(1.0,2.0,3.0);
    Color c2(2.0,4.0,6.0);

    TS_ASSERT_EQUALS(c2-c1, c1);
    
    c2-=c1;
    TS_ASSERT_EQUALS(c2,c1);
  }
  void testColorClamp(void) {
    Color c1(1.0,2.0,3.0);
    Color c2(2.0,4.0,6.0);
    Color c3(-1.0,-1.0,-1.0);
    Color c4(-1.0,2.0,0.5);
    
    TS_ASSERT_EQUALS(c1.clamp(), Color(1.0,1.0,1.0));
    TS_ASSERT_EQUALS(c2.clamp(), Color(1.0,1.0,1.0));
    TS_ASSERT_EQUALS(c3.clamp(), Color(0.0,0.0,0.0));
    TS_ASSERT_EQUALS(c4.clamp(), Color(0.0,1.0,0.5));
  }
  void testColorIntensity(void) {
    Color c1(1.0,2.0,3.0);
    
    TS_ASSERT_EQUALS(c1.intensity(), std::sqrt(1.0+4.0+9.0));
  }
  void testRayPointOn(void) {
    Point o1(0.0,0.0,0.0);
    Vector v1(1.0,0.0,0.0);
    Ray r1(o1,v1);
    
    Point o2(0.0,0.0,0.0);
    Vector v2(1.0,1.0,0.0);
    Ray r2(o2,v2);
    
    TS_ASSERT_EQUALS(r1.pointOn(1.0), Point(1.0,0.0,0.0));
    TS_ASSERT_EQUALS(r2.pointOn(1.0), Point(1.0,1.0,0.0));
  }
  void testCameraLocation(void) {
    Camera c1(Point(1.0,0.0,0.0), Point(0.0,0.0,0.0));
    Camera c2(Point(1.0,0.0,1.0), Point(0.0,0.0,0.0));

    TS_ASSERT_EQUALS(c1.getDirection(), Vector(-1.0,0.0,0.0));
    TS_ASSERT_EQUALS(c2.getDirection(), Vector(-1.0,0.0,-1.0).normal());
    c2.setLocation(Point(1.0,1.0,1.0));
    TS_ASSERT_EQUALS(c2.getDirection(), Vector(-1.0,-1.0,-1.0).normal());
  }
  void testCameraUp(void) {
    Camera c1(Point(1.0,0.0,0.0), Point(0.0,0.0,0.0), Vector(0.0,1.0,0.0));
    Camera c2(Point(1.0,0.0,1.0), Point(0.0,0.0,0.0), Vector(0.0,1.0,0.0));

    TS_ASSERT_EQUALS(c1.getUp(),
		     Vector(-1.0,0.0,0.0).
		     cross(Vector(0.0,1.0,0.0)).
		     cross(Vector(-1.0,0.0,0.0)));
    TS_ASSERT_EQUALS(c2.getUp(),
		     Vector(-1.0,0.0,-1.0).normal().
		     cross(Vector(0.0,1.0,0.0).normal()).
		     cross(Vector(-1.0,0.0,-1.0).normal()));
    c2.setLocation(Point(1.0,1.0,1.0));
    TS_ASSERT_EQUALS(c2.getUp(),
		     (Vector(-1.0,-1.0,-1.0).normal()).
		     cross(Vector(0.0,1.0,0.0)).
		     cross(Vector(-1.0,-1.0,-1.0).normal()));
  }
  void testCameraLookAt(void) {
    Camera c1(Point(1.0,0.0,0.0), Point(0.0,0.0,0.0));
    Camera c2(Point(1.0,0.0,1.0), Point(0.0,0.0,0.0));
    c2.setLookAt(Point(1.0,1.0,1.0));

    Vector temp(Vector(0.0,1.0,0.0).normal());
    TS_ASSERT_EQUALS(c2.getDirection(), temp);
  }
  void testTriangleExtents(void) {
    Triangle t1(Point(0.0,0.0,0.0), Point(1.0,1.0,0.0), Point(1.0,0.0,0.0));
    real xmin;
    real xmax;
    real ymin;
    real ymax;
    real zmin;
    real zmax;
    t1.getExtents(xmin,xmax,ymin,ymax,zmin,zmax);
    TS_ASSERT_EQUALS(xmin,0.0);
    TS_ASSERT_EQUALS(xmax,1.0);
    TS_ASSERT_EQUALS(ymin,0.0);
    TS_ASSERT_EQUALS(ymax,1.0);
    TS_ASSERT_EQUALS(zmin,0.0);
    TS_ASSERT_EQUALS(zmax,0.0);
  }
  void testTriangleIntersection(void) {
    // This is just about the easiest test case
    // TODO: Add non-trivial test
    Triangle t1(Point(-1.0,-1.0,0.0),
		Point(-1.0,2.0,0.0),
		Point(2.0,-1.0,0.0),
		0,
		true);
    Ray r1(Point(0.0,0.0,1.0),
	   Vector(0.0,0.0,-1.0));
    
    Intersection test=t1.intersect(r1,true);
    TS_ASSERT_EQUALS(test.hits(), true);
    TS_ASSERT_EQUALS(test.normal(), Vector(0.0,0.0,1.0));
    TS_ASSERT_EQUALS(test.object(), &t1);
    TS_ASSERT_EQUALS(test.t(), 1.0);
  }
  void testSphereExtents(void) {
    Sphere s1(Point(0.0,0.0,0.0), 1.0);
    real xmin;
    real xmax;
    real ymin;
    real ymax;
    real zmin;
    real zmax;
    
    s1.getExtents(xmin,xmax,ymin,ymax,zmin,zmax);
    
    TS_ASSERT_EQUALS(xmin,-1.0);
    TS_ASSERT_EQUALS(xmax,1.0);
    TS_ASSERT_EQUALS(ymin,-1.0);
    TS_ASSERT_EQUALS(ymax,1.0);
    TS_ASSERT_EQUALS(zmin,-1.0);
    TS_ASSERT_EQUALS(zmax,1.0);
  }
  
  void testSphereIntersection(void) {
    // Again, just about the easiest test case
    // TODO: Add non-trivial test
    
    Sphere s1(Point(2.0,0.0,0.0), 1.0);
    
    Ray r1(Point(0.0,0.0,0.0),
	   Vector(1.0,0.0,0.0));
    
    Intersection test=s1.intersect(r1,true);
    
    TS_ASSERT_EQUALS(test.hits(), true);
    TS_ASSERT_EQUALS(test.normal(), Vector(-1.0,0.0,0.0));
    TS_ASSERT_EQUALS(test.object(), &s1);
    TS_ASSERT_EQUALS(test.t(), 1.0);
  }
  void testLightRayTo(void) {
    Light l1(Point(1.0,1.0,1.0), Color(1.0,0.5,0.0));
    Ray r1(Point(0.0,0.0,0.0), Vector(1.0,1.0,1.0).normal());

    Ray test=l1.getRayTo(Point(0.0,0.0,0.0));
    TS_ASSERT_EQUALS(test.getOrigin(), r1.getOrigin());
    TS_ASSERT_EQUALS(test.getDir(), r1.getDir());
  }
  void testImagePixels(void) {
    Image i1(2,2);
    Color white(1.0,1.0,1.0);

    i1(0,0)=white;
    TS_ASSERT_THROWS(i1(4,4)=white, std::runtime_error);
    TS_ASSERT_EQUALS(i1.getPixel(0,0), white);
    TS_ASSERT_THROWS(i1.getPixel(4,4), std::runtime_error);
    TS_ASSERT_THROWS_NOTHING(i1(1,1)=white);
    TS_ASSERT_EQUALS(i1.getPixel(1,1), white);
  }
  void testImageToPPM(void) {
    std::ostringstream test;
    Image i1(2,2);
    Color white(1.0,1.0,1.0);

    i1(0,0)=white;
    i1(1,1)=white;
    i1.toPPM(test);
    TS_ASSERT_EQUALS(test.str(), "P3\n2 2\n255\n255 255 255  0 0 0  0 0 0  255 255 255  ");
    
    std::ostringstream test2;
    Image i2(4,4);

    i2(0,0)=white;
    i2(1,1)=white;
    i2(2,2)=white;
    i2(3,3)=white;
    
    i2.toPPM(test2);
    std::string temp(test2.str());

    int count=-1;
    std::string::size_type li=0;
    while ((li=temp.find("\n", li+1)) != std::string::npos) {
      ++count;
    }
    TS_ASSERT(count>=4);
  }
};
