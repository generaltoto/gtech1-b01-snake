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
<<<<<<< HEAD
  delete sk, fr, wdw;
=======
  a.deleteObject();
>>>>>>> c9df717181aa003104691ddc3275b6ee268ddc42
  return 0;
}