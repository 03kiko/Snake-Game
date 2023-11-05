#include "Snake.h"

Snake::Snake(int x, int y)
  : head(x, y),    
    dir(STOP) {}

void Snake::updateSnakeDirection(char direction) {
  switch (direction) {
    case 'a':
      if(dir != RIGHT)
        dir = LEFT;
      break;
    case 'd':
	    if(dir != LEFT)
        dir = RIGHT;
	    break;
    case 'w':
      if(dir != DOWN)
	      dir = UP;
	    break;
    case 's':
	    if(dir != UP)
        dir = DOWN;
	    break;
  }
}

void Snake::MoveSnake() {
  MoveSnakeTail();
  MoveSnakeHead();
}

void Snake::MoveSnakeTail() {
  if(tail.empty())
    return;
  
  Coordinate prev = tail[0];
  tail[0] = head;
  for(int i = 1; i <  tail.size(); i++) {
    Coordinate temp = tail[i];
    tail[i] = prev;
    prev = temp;
  } 
}

void Snake::MoveSnakeHead() {  
  switch (dir) {
    case LEFT:
      head.setXCoord(head.getXCoord() - 1);
      break;
    case RIGHT:
      head.setXCoord(head.getXCoord() + 1);
      break;
    case UP:
      head.setYCoord(head.getYCoord() - 1);
      break;
    case DOWN:
      head.setYCoord(head.getYCoord() + 1);
      break;
  }
}

void Snake::growTail() {
  tail.push_back(head);
}

void Snake::clearTail() {
  tail.clear();
}

bool Snake::checkSelfColision() {
  for(const auto& segment: tail)
    if(head == segment)
      return true;
  return false;
}

Coordinate Snake::getHead() {
    return head;
}

void Snake::setHeadCoordinate(int x, int y) {
  head.setXCoord(x);
  head.setYCoord(y);
}

std::vector<Coordinate> Snake::getTail() {
    return tail;
}