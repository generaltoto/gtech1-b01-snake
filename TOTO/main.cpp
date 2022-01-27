#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"

bool done = false;

int main (void)
{
  application a;
  a.initGame();
  while (!done)
  {
    done = a.runGAme(done);
  }
  a.deleteObject();
  return 0;
}