#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"

bool done = false;

int main (void) {
  Application a;
  a.initGame();
  while (!done){
    done = a.runGame(done);
  }
  a.deleteObject();
  return 0;
}