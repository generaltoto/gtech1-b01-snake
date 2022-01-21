#include "classes.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

int main (int argc, char *argv[])
{
  bool done = false;

  MainSDLWindow *wdw = new MainSDLWindow;
  wdw->init();
  while (!done)
  {
    wdw->redraw();
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }

  return 0;
}