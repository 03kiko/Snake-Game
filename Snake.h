#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>
#include "Coordinate.h"

class Snake {
private:
  Coordinate head;
  std::vector<Coordinate> tail;
  enum Direction {STOP, LEFT, RIGHT, UP, DOWN};
  Direction dir;
public:
  Snake(int x, int y);
  void updateSnakeDirection(char direction);
  void MoveSnake();
  void MoveSnakeTail();
  void MoveSnakeHead();
  void growTail();
  void clearTail();
  Coordinate getHead();
  void setHeadCoordinate(int x, int y);
  std::vector<Coordinate> getTail();
  bool checkSelfColision();
};

#endif
