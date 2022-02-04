#include <SDL2/SDL.h>
#include <iostream>
#include "application.hpp"

using namespace std;

bool done = false;
bool replay = true;

int main (void) {
  Application a;
  do {
    done = false;
    cout << "start" << endl;
    a.initGame();
    while (!done) {
      done = a.runGame(done);
    }
    replay = a.replay();
    a.deleteObject();
    a.deleteWindow();
   } while (replay);
  return 0;
}