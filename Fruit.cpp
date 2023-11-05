#include "Fruit.h"

Fruit::Fruit(int x, int y)
  : position(x, y) {}

Coordinate Fruit::getPosition() {
    return position;
}

void Fruit::setPosition(int x, int y) {
  position.setXCoord(x);
  position.setYCoord(y);
}