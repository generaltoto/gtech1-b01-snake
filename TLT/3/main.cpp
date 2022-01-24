#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20


int main (void) {
  bool done = false;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale

  MainSDLWindow *wdw = new MainSDLWindow();
  wdw->init(WIDTH);
  Square *c = new Square();

  while (!done) {
    wdw->draw(sizeOfSquare, WIDTH, GRID_SIZE);
    c->draw(sizeOfSquare,wdw->getRenderer()); //dessin du cube depuis =cube.pp= fonction =draw()=
    SDL_RenderPresent(wdw->getRenderer());

    SDL_Event event;
    
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
  return 0;
}