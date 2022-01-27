#pragma once 

#include <SDL2/SDL.h>

#define WIDTH 1000
#define GRID_SIZE 35


class application 
{
private:

  int score;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE);

public: 

  void initGame(void);

  bool runGAme(bool done);

  int getScore(int score);

  void deleteObject(void);
};