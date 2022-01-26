#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"

#define WIDTH 900
#define GRID_SIZE 20

bool done = false;
int sizeOfSquare = floor(WIDTH / GRID_SIZE);
int score = 0;

int main (void)
{
  application a;
  a.initGame(WIDTH, GRID_SIZE, score);
  while (!done)
  {
    done = a.runGAme(sizeOfSquare, WIDTH, GRID_SIZE, score, done);
  }
  return 0;
}