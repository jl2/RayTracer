/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "tests.h"

static TestSuite suite_TestSuite;

static CxxTest::List Tests_TestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestSuite( "tests.h", 18, "TestSuite", suite_TestSuite, Tests_TestSuite );

static class TestDescription_TestSuite_testPointVectorAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testPointVectorAddition() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 27, "testPointVectorAddition" ) {}
 void runTest() { suite_TestSuite.testPointVectorAddition(); }
} testDescription_TestSuite_testPointVectorAddition;

static class TestDescription_TestSuite_testPointVectorPlusEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testPointVectorPlusEquals() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 39, "testPointVectorPlusEquals" ) {}
 void runTest() { suite_TestSuite.testPointVectorPlusEquals(); }
} testDescription_TestSuite_testPointVectorPlusEquals;

static class TestDescription_TestSuite_testPointEquals : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testPointEquals() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 51, "testPointEquals" ) {}
 void runTest() { suite_TestSuite.testPointEquals(); }
} testDescription_TestSuite_testPointEquals;

static class TestDescription_TestSuite_testPointMinus : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testPointMinus() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 59, "testPointMinus" ) {}
 void runTest() { suite_TestSuite.testPointMinus(); }
} testDescription_TestSuite_testPointMinus;

static class TestDescription_TestSuite_testVectorEqual : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorEqual() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 68, "testVectorEqual" ) {}
 void runTest() { suite_TestSuite.testVectorEqual(); }
} testDescription_TestSuite_testVectorEqual;

static class TestDescription_TestSuite_testVectorScale : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorScale() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 81, "testVectorScale" ) {}
 void runTest() { suite_TestSuite.testVectorScale(); }
} testDescription_TestSuite_testVectorScale;

static class TestDescription_TestSuite_testVectorLength : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorLength() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 90, "testVectorLength" ) {}
 void runTest() { suite_TestSuite.testVectorLength(); }
} testDescription_TestSuite_testVectorLength;

static class TestDescription_TestSuite_testVectorNormal : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorNormal() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 107, "testVectorNormal" ) {}
 void runTest() { suite_TestSuite.testVectorNormal(); }
} testDescription_TestSuite_testVectorNormal;

static class TestDescription_TestSuite_testVectorDot : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorDot() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 120, "testVectorDot" ) {}
 void runTest() { suite_TestSuite.testVectorDot(); }
} testDescription_TestSuite_testVectorDot;

static class TestDescription_TestSuite_testVectorCross : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testVectorCross() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 135, "testVectorCross" ) {}
 void runTest() { suite_TestSuite.testVectorCross(); }
} testDescription_TestSuite_testVectorCross;

static class TestDescription_TestSuite_testColorScale : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testColorScale() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 147, "testColorScale" ) {}
 void runTest() { suite_TestSuite.testColorScale(); }
} testDescription_TestSuite_testColorScale;

static class TestDescription_TestSuite_testColorAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testColorAddition() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 156, "testColorAddition" ) {}
 void runTest() { suite_TestSuite.testColorAddition(); }
} testDescription_TestSuite_testColorAddition;

static class TestDescription_TestSuite_testColorSubtraction : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testColorSubtraction() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 165, "testColorSubtraction" ) {}
 void runTest() { suite_TestSuite.testColorSubtraction(); }
} testDescription_TestSuite_testColorSubtraction;

static class TestDescription_TestSuite_testColorClamp : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testColorClamp() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 174, "testColorClamp" ) {}
 void runTest() { suite_TestSuite.testColorClamp(); }
} testDescription_TestSuite_testColorClamp;

static class TestDescription_TestSuite_testColorIntensity : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testColorIntensity() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 185, "testColorIntensity" ) {}
 void runTest() { suite_TestSuite.testColorIntensity(); }
} testDescription_TestSuite_testColorIntensity;

static class TestDescription_TestSuite_testRayPointOn : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testRayPointOn() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 190, "testRayPointOn" ) {}
 void runTest() { suite_TestSuite.testRayPointOn(); }
} testDescription_TestSuite_testRayPointOn;

static class TestDescription_TestSuite_testCameraLocation : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testCameraLocation() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 202, "testCameraLocation" ) {}
 void runTest() { suite_TestSuite.testCameraLocation(); }
} testDescription_TestSuite_testCameraLocation;

static class TestDescription_TestSuite_testCameraUp : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testCameraUp() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 211, "testCameraUp" ) {}
 void runTest() { suite_TestSuite.testCameraUp(); }
} testDescription_TestSuite_testCameraUp;

static class TestDescription_TestSuite_testCameraLookAt : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testCameraLookAt() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 229, "testCameraLookAt" ) {}
 void runTest() { suite_TestSuite.testCameraLookAt(); }
} testDescription_TestSuite_testCameraLookAt;

static class TestDescription_TestSuite_testTriangleExtents : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testTriangleExtents() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 237, "testTriangleExtents" ) {}
 void runTest() { suite_TestSuite.testTriangleExtents(); }
} testDescription_TestSuite_testTriangleExtents;

static class TestDescription_TestSuite_testTriangleIntersection : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testTriangleIntersection() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 253, "testTriangleIntersection" ) {}
 void runTest() { suite_TestSuite.testTriangleIntersection(); }
} testDescription_TestSuite_testTriangleIntersection;

static class TestDescription_TestSuite_testSphereExtents : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testSphereExtents() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 270, "testSphereExtents" ) {}
 void runTest() { suite_TestSuite.testSphereExtents(); }
} testDescription_TestSuite_testSphereExtents;

static class TestDescription_TestSuite_testSphereIntersection : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testSphereIntersection() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 289, "testSphereIntersection" ) {}
 void runTest() { suite_TestSuite.testSphereIntersection(); }
} testDescription_TestSuite_testSphereIntersection;

static class TestDescription_TestSuite_testLightRayTo : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testLightRayTo() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 305, "testLightRayTo" ) {}
 void runTest() { suite_TestSuite.testLightRayTo(); }
} testDescription_TestSuite_testLightRayTo;

static class TestDescription_TestSuite_testImagePixels : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testImagePixels() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 313, "testImagePixels" ) {}
 void runTest() { suite_TestSuite.testImagePixels(); }
} testDescription_TestSuite_testImagePixels;

static class TestDescription_TestSuite_testImageToPPM : public CxxTest::RealTestDescription {
public:
 TestDescription_TestSuite_testImageToPPM() : CxxTest::RealTestDescription( Tests_TestSuite, suiteDescription_TestSuite, 324, "testImageToPPM" ) {}
 void runTest() { suite_TestSuite.testImageToPPM(); }
} testDescription_TestSuite_testImageToPPM;

#include <cxxtest/Root.cpp>
