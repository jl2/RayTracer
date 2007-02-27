
#include "object.h"

Object::Object(Texture *text) : txt(text),
				numCells(0) {}

Texture *Object::getTexture() {
  return txt;
}

void Object::setTexture(Texture *text) {
  txt = text;
}
int Object::getNumCells() {
  return numCells;
}
void Object::incCellCount() {
  ++numCells;
}
  
