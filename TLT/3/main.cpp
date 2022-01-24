#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 600
#define GRID_SIZE 20

int main (void) {
  int frame_rate = 20;
  bool done = false;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale

  MainSDLWindow *wdw = new MainSDLWindow();
  Square *s = new Square();

  wdw->init(WIDTH);

  while (!done) {
    int frame_time_start = SDL_GetTicks();

    SDL_RenderClear(wdw->getRenderer());
    wdw->draw(sizeOfSquare, WIDTH, GRID_SIZE);
    s->draw(sizeOfSquare,wdw->getRenderer());
    s->move();
    SDL_RenderPresent(wdw->getRenderer());
    SDL_UpdateWindowSurface(wdw->getWindow());

    int frame_time_interval = SDL_GetTicks() - frame_time_start;
    SDL_Delay(frame_time_interval);

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
  return 0;
}