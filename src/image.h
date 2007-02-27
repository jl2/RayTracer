#ifndef RAY_TRACE_IMAGE_H
#define RAY_TRACE_IMAGE_H

#include <ostream>
#include "globaldefs.h"
#include "color.h"

// The Image class stores an array of colors that represent an image.
class Image {
 public:
  Image(int w, int h);
  ~Image();
  Color &operator()(int x, int y);
  Color &getPixel(int x, int y);    
  int getHeight();
  int getWidth();
  void toPPM(std::ostream &out);
 private:
  Color *image;
  int width, height;
};

#endif
