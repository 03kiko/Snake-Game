#ifndef _FRUIT_H_
#define _FRUIT_H_

#include "Coordinate.h"

class Fruit {
private:
  Coordinate position;
public:
  Fruit(int x, int y);
  Coordinate getPosition();
  void setPosition(int newX, int newY);
};

#endif

