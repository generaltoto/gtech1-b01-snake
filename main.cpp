#include <SDL2/SDL.h>
#include "application.hpp"

bool done;

int main (void) {
  Application a; //using app object 
  a.initWindow();
  do {
    done = false;
    a.initGame();
    while (!done) { //game loop
      done = a.runGame(done);
    }
    a.deleteObject();
   } while (a.replay()); //replay loop
   a.deleteWindow();
  return 0;
}