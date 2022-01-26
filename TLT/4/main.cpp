#include <SDL2/SDL.h>
#include <iostream>
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"

#define WIDTH 700                                                        //900px grid
#define GRID_SIZE 20                                                     //20 rows grid

bool done = false;                                                       //"global" variables from main
int sizeOfSquare = floor(WIDTH / GRID_SIZE);
int score = 0;

int main (void)
{
  srand(time(0));

  MainSDLWindow *wdw = new MainSDLWindow;                                 //getting =MainSDLWindow= class as =wdw=
  snake *sk = new snake;
  fruit *fr = new fruit;                                                  //getting =fruit=         class as =fr=
  Uint32 frameStart, frameTime, frameDelay = 80;                          //frame delay init, the greater the slower

  wdw->init(WIDTH, score);                                                //window init
  fr->initApple(GRID_SIZE, sk->posX, sk->posY);                                               //apple init
  
  while (!done)
  {
    frameStart = SDL_GetTicks();                                          //number of second since initialization
    SDL_RenderClear(wdw->getRenderer());                                  //clearing renderer

    wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);                      //disp grid

    sk->drawHead(sizeOfSquare, wdw->getRenderer());                           //disp square
    fr->randomApple(sizeOfSquare, wdw->getRenderer());                    //random Apple position
    
    if (sk->isOnApple(fr->appleX, fr->appleY) == true)
    {
      score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);   //checking eat apple, score += 1 if so
    }
    wdw->draw_number(score, 10, WIDTH+10);
    done = sk->collision(GRID_SIZE);                                      //checking for collisions

    SDL_SetRenderDrawColor(wdw->getRenderer(), 0, 0, 0, 255);

    SDL_RenderPresent(wdw->getRenderer());                                //disp everything on window

    SDL_UpdateWindowSurface(wdw->getWindow());                            //update window
    sk->move();                                                           //checking for moves

    frameTime = SDL_GetTicks() - frameStart;                              //framerate managing 
		if ( frameTime < frameDelay )
		{
			SDL_Delay( frameDelay - frameTime );
		}
    
    SDL_Event event;                                                      //checking for quit event
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        done = SDL_TRUE;
      }
    }
  }
  delete sk, fr, wdw;
  return 0;
}