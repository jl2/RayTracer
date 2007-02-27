// gridentry.h - GridEntry class declaration

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

#ifndef RAY_TRACE_GRID_ENTRY_H
#define RAY_TRACE_GRID_ENTRY_H

class GridEntry {
 public:
  GridEntry();
  ~GridEntry();
  void addObject(Object *obj);
  void addLight(Light *lght);
  Intersection intersect(Ray r, bool computeNormal, unsigned int *int_test,
			 unsigned int *int_hit);
  int getNumObjs();
 private:
  ObjectList objects;
  LightList lights;
  int objCount;
};

#endif
