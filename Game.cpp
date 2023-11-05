#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <algorithm>
#include "Game.h"

const int sleepDuration = 200;

Game::Game(int width, int height)
  : width(width),
    height(height),
    isGameOver(false),
    snake(width / 2, height / 2),
    fruit(rand() % (width - 2) + 1, rand() % (height - 2) + 1),
    grid(height, std::vector<char>(width, '#')),
    score(0) {
    
    spawnFruit();
  }

void Game::start() {
  while(!isGameOver) {
    updateGrid();
    draw();
    input();
    logic();
    std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
  }
}

void Game::initialiseGrid() {
  for(int i = 0; i < height; i++) {
    for(int j = 0; j < width; j++) {
      if(i == 0 || i == height - 1 || j == 0 || j == width - 1)
        continue;
      else
        grid[i][j] = ' ';
    }
  }
}

void Game::updateGrid() {
  initialiseGrid();
  
  grid[snake.getHead().getYCoord()][snake.getHead().getXCoord()] = 'O';
  grid[fruit.getPosition().getYCoord()][fruit.getPosition().getXCoord()] = 'F';

  for(auto& segment: snake.getTail())
    grid[segment.getYCoord()][segment.getXCoord()] = 'o';
}

void Game::spawnFruit() {
  std::vector<Coordinate> snakeCoords = snake.getTail();
  snakeCoords.push_back(snake.getHead());

  int availableCoords = (width - 2)*(width - 2) - snakeCoords.size();

  if(availableCoords != 0) {
    bool fruitOnSnake = false;
    do {
      fruitOnSnake = false;
      fruit.setPosition(rand() % (width - 2) + 1, rand() % (height - 2) + 1);
      
      if(std::find(snakeCoords.begin(), snakeCoords.end(),
                   fruit.getPosition()) != snakeCoords.end())
        fruitOnSnake = true;
      
    } while (fruitOnSnake);
  } else
    isGameOver = true;
}

void Game::draw() {
  system("clear");

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      std::cout << grid[i][j];
    }
  
    std::cout << std::endl;
  }

  std::cout << "Score:" << score << std::endl;
  std::cout << "\nPress 'x' to end game\n";
}

void Game::input() {
  if(_kbhit()) {
    char ch = getch();
    if(ch == 'x')
      isGameOver = true;
	  else
      snake.updateSnakeDirection(ch);
  }
}

void Game::logic() {
  snake.MoveSnake();
  
  Coordinate head = snake.getHead();
  int x = head.getXCoord();
  int y = head.getYCoord();

  if (x >= width - 1)
    x = 1;
  else if (x <= 0)
    x = width - 2;

  if (y >= height - 1)
    y = 1;
  else if (y <= 0)
    y = height - 2;

  snake.setHeadCoordinate(x, y);
  
  if(snake.checkSelfColision())
    isGameOver = true;
  
  if(snake.getHead() == fruit.getPosition()) {
    score += 10;
    spawnFruit();
    snake.growTail();
  }
}

void Game::drawGameOver() {
  system("clear");
  std::cout << std::endl;
  std::cout << "                                    \n";
  std::cout << "███▀▀▀██ ███▀▀▀███ ███▀█▄█▀███ ██▀▀▀\n";
  std::cout << "██    ██ ██     ██ ██   █   ██ ██   \n";
  std::cout << "██   ▄▄▄ ██▄▄▄▄▄██ ██   ▀   ██ ██▀▀▀\n";
  std::cout << "██    ██ ██     ██ ██       ██ ██   \n";
  std::cout << "███▄▄▄██ ██     ██ ██       ██ ██▄▄▄\n";
  std::cout << "                                    \n";
  std::cout << "███▀▀▀███ ▀███  ██▀ ██▀▀▀ ██▀▀▀▀██▄ \n";
  std::cout << "██     ██   ██  ██  ██    ██     ██ \n";
  std::cout << "██     ██   ██  ██  ██▀▀▀ ██▄▄▄▄▄▀▀ \n";
  std::cout << "██     ██   ██  █▀  ██    ██     ██ \n";
  std::cout << "███▄▄▄███    ▀█▀    ██▄▄▄ ██     ██▄\n";
  std::cout << "                                    \n";
  std::cout << "        ██               ██         \n";
  std::cout << "      ████▄   ▄▄▄▄▄▄▄   ▄████       \n";
  std::cout << "         ▀▀█▄█████████▄█▀▀          \n";
  std::cout << "           █████████████            \n";
  std::cout << "           ██▀▀▀███▀▀▀██            \n";
  std::cout << "           ██   ███   ██            \n";
  std::cout << "           █████▀▄▀█████            \n";
  std::cout << "            ███████████             \n";
  std::cout << "        ▄▄▄██  █▀█▀█  ██▄▄▄         \n";
  std::cout << "        ▀▀██           ██▀▀         \n";
  std::cout << "          ▀▀           ▀▀           \n";
  std::cout << "                                    \n";
  std::cout << "\nSCORE:" << score <<"\n";
  std::cout << "\nPRESS:\n-'r' to restart game\n-'x' to end game\n";
}

void Game::gameOver() {
  drawGameOver();
  while(true) {
    if(_kbhit()) {
      char ch = getchar();
      if(ch == 'x')
        break;
      if(ch == 'r') {
        reset();
        start();
        drawGameOver();
      }
    }
  }
}

void Game::reset() {
  isGameOver = false;
  snake = Snake(width / 2, height / 2);
  snake.clearTail();
  fruit = Fruit(rand() % (width - 2) + 1, rand() % (height - 2) + 1);
  spawnFruit();
  score = 0;
}