#include "Game.h"

const int gameSize = 25;

int main() {
  Game game(gameSize, gameSize);
  game.start();
  game.gameOver();       
  return 0;
}