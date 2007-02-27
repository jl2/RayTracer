#include <cmath>

#include "image.h"

Image::Image(int w, int h) : width(w), height(h) {
  image = new Color[w*h];
}
Image::~Image() {
  delete [] image;
  width=0;
  height=0;
}
Color &Image::operator()(int x, int y) {
  return getPixel(x,y);
}
Color &Image::getPixel(int x, int y) {
  return image[(y*width)+x];
}
    
int Image::getHeight() {
  return height;
}
int Image::getWidth() {
  return width;
}

void Image::toPPM(std::ostream &out) {
  out << "P3\n";
  out << width << " " << height << "\n";
  out << "255";
    for (int i = 0; i < width*height; ++i) {
      if (i % (70/13)==0)
	out << "\n";
      out << int(255*std::abs(image[i].red())) << " "
	  << int(255*std::abs(image[i].green())) << " "
	  << int(255*std::abs(image[i].blue())) << "  ";

  }
}
