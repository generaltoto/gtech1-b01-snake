#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20

bool done = false;
int sizeOfSquare = floor(WIDTH / GRID_SIZE);          //"global" variable from main


int main (void)
{
  MainSDLWindow *wdw = new MainSDLWindow;             //getting classes
  square *sq = new square;
  Uint32 frameStart, frameTime, frameDelay = 90;      //frame delay init, the greater the slower

  wdw->init(WIDTH);                                   //window init
  sq->initApple();                                    //apple init
  
  while (!done)
  {
    frameStart = SDL_GetTicks();                       //number of second since initialization
    SDL_RenderClear(wdw->getRenderer());               //clearing renderer

    wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);   //disp grid

    sq->draw(sizeOfSquare, wdw->getRenderer());        //disp square
    sq->randomApple(sizeOfSquare, wdw->getRenderer()); //random Apple position
    
    sq->move();                                        //checking for moves
    sq->eatApple(sizeOfSquare, wdw->getRenderer());    //checking eat apple
    done = sq->collision();                            //checking for collisions

    SDL_RenderPresent(wdw->getRenderer());             //disp everything on window

    SDL_UpdateWindowSurface(wdw->getWindow());         //update window

    frameTime = SDL_GetTicks() - frameStart;           //framerate managing 
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
    
    SDL_Event event;                                   //checking for quit event
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }

  return 0;
}