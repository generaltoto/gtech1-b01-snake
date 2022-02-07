#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"

bool done = false;
bool replay = true;

int main (void) {
  do {
    Application a;
    a.initGame();
    while (!done) {
      done = a.runGame(done);
    }
    a.deleteObject();

  } while (replay);
  
  return 0;
}