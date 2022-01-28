#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

#include "mainSDLWindow.hpp"
#include "square.hpp"
#include "fruit.hpp"

#define WIDTH 700
#define GRID_SIZE 30

int main (void) {
  srand(time(0));
  Uint32 frameStart, frameTime, frameDelay = 100;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE); //déclaration dans main pour utilisation globale
  bool done = false;
  int score = 0;

  MainSDLWindow *wdw = new MainSDLWindow();
  Square *s = new Square();
  fruit *fr = new fruit(); 

  int posX, posY = s->getPos();
  wdw->init(WIDTH);
  fr->initApple(GRID_SIZE,posX,posY);
  
  while (!done) {
    frameStart = SDL_GetTicks();
    if (s->isOnApple(fr->appleX, fr->appleY) == true) {
      score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE,posX,posY);   //checking eat apple, score += 1 if so
      s->draw(sizeOfSquare,wdw->getRenderer());
    }
    
    done = s->collision(GRID_SIZE);  

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
    bool axe = false;
    s->move(sizeOfSquare, axe);
    SDL_RenderClear(wdw->getRenderer());
    //wdw->draw(sizeOfSquare, WIDTH, GRID_SIZE);
    s->draw(sizeOfSquare,wdw->getRenderer());
    fr->randomApple(sizeOfSquare, wdw->getRenderer());
    SDL_RenderPresent(wdw->getRenderer()); 

    frameTime = SDL_GetTicks() - frameStart;
    if ( frameTime < frameDelay ) {
			SDL_Delay( frameDelay - frameTime );
		}
  }
  return 0;
}