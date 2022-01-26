#include <SDL2/SDL.h>
#include <iostream>

#include "mainSDLWindow.hpp"
#include "square.hpp"

#define WIDTH 900                                     //900px grid
#define GRID_SIZE 20                                  //20 rows grid

bool done = false;                                    //"global" variables from main
int sizeOfSquare = floor(WIDTH / GRID_SIZE);
int score = 0;

int main (void)
{
  MainSDLWindow *wdw = new MainSDLWindow;                      //getting =MainSDLWindow= class as =wdw=
  square *sq = new square;                                     //getting =square=        class as =sq=
  Uint32 frameStart, frameTime, frameDelay = 90;               //frame delay init, the greater the slower

  wdw->init(WIDTH, score);                                     //window init
  sq->initApple();                                             //apple init
  
  while (!done)
  {
    frameStart = SDL_GetTicks();                               //number of second since initialization
    SDL_RenderClear(wdw->getRenderer());                       //clearing renderer

    wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);           //disp grid

    sq->draw(sizeOfSquare, wdw->getRenderer());                //disp square
    sq->randomApple(sizeOfSquare, wdw->getRenderer());         //random Apple position
    
    sq->move();                                                //checking for moves
    score = sq->eatApple(sizeOfSquare, wdw->getRenderer());    //checking eat apple, score += 1 if so
    done = sq->collision();                                    //checking for collisions

    SDL_RenderPresent(wdw->getRenderer());                     //disp everything on window

    SDL_UpdateWindowSurface(wdw->getWindow());                 //update window

    frameTime = SDL_GetTicks() - frameStart;                   //framerate managing 
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
    
    SDL_Event event;                                           //checking for quit event
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
  std::cout << score << std::endl;

  return 0;
}