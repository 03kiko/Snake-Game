#ifndef _GAME_H_
#define _GAME_H_

#include "Snake.h"
#include "Fruit.h"

class Game {
private:
  std::vector<std::vector<char>> grid;
  Snake snake;
  Fruit fruit;
  const int width, height;
  bool isGameOver;
  int score;
  void spawnFruit();
  void initialiseGrid();
  void updateGrid();
  void draw();
  void input();
  void logic();
  void drawGameOver();
  void reset();
public:
  Game(int width, int height);
  void start();
  void gameOver();
};

#endif 
