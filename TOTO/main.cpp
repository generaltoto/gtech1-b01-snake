#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "cube.hpp"

#define WIDTH 900
#define GRID_SIZE 20


int main (void)
{
  bool done = false;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale

  MainSDLWindow *wdw = new MainSDLWindow;
  wdw->init(WIDTH);

  while (!done)
  {
    wdw->redraw(sizeOfSquare, WIDTH, GRID_SIZE);
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }

  return 0;
}