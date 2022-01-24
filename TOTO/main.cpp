#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20


int main (void)
{
  bool done = false;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale

  MainSDLWindow *wdw = new MainSDLWindow;
  square *sq = new square;

  wdw->init(WIDTH);
  
  while (!done)
  {
    SDL_RenderClear(wdw->getRenderer());

    wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);

    sq->draw(sizeOfSquare, wdw->getRenderer());
    sq->move();

    SDL_RenderPresent(wdw->getRenderer());

    SDL_UpdateWindowSurface(wdw->getWindow());
    
    SDL_Delay(10);
    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }

  return 0;
}