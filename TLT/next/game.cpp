#include "classes.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

Snake *snake = new Snake;

int main (int argc, char *argv[])
{
  bool done = false;

  MainSDLWindow *wdw = new MainSDLWindow;
  wdw->init();
  while (!done)
  {
    int size = wdw->redraw();
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }

    snake->head(wdw.window, wdw.renderer);
  }

  return 0;
}

void keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
    snake.x += 1;
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    snake.x -= 1;
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    snake.y -= 1;
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    snake.y += 1;
  }
}