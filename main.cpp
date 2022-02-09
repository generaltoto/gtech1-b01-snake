#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"

using namespace std;

bool done;

int main (void) {
  Application a;
  a.initWindow();
  do {
    done = false;
    a.initGame();
    while (!done) {
      done = a.runGame(done);
    }
    a.deleteObject();
   } while (!done);
   a.deleteWindow();
  return 0;
}