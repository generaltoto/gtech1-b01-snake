#pragma once 

#include <SDL2/SDL.h>

#define WIDTH 700
#define GRID_SIZE 25


class Application 
{
private:

  int score;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE);

public: 

  void initGame(void);

  bool runGame(bool done);

  int getScore(int score);

  void deleteObject(void);
};