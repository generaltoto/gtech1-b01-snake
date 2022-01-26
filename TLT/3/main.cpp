#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 600
#define GRID_SIZE 20

int main (void) {
  Uint32 frameStart, frameTime, frameDelay = 50;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale
  bool done = false;

  MainSDLWindow *wdw = new MainSDLWindow();
  Square *s = new Square();

  wdw->init(WIDTH);
  

  while (!done) {
    frameStart = SDL_GetTicks();

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }else if(event.type == SDL_KEYDOWN) {
        switch(event.key.keysym.sym){
          case SDLK_ESCAPE:
            done = SDL_TRUE;
            break;
        }
      }
    }
    s->move(sizeOfSquare);
    //wdw->draw(sizeOfSquare, WIDTH, GRID_SIZE);
    s->draw(sizeOfSquare,wdw->getRenderer());

    frameTime = SDL_GetTicks() - frameStart;
    if ( frameTime < frameDelay ) {
			SDL_Delay( frameDelay - frameTime );
		}
  }
  return 0;
}