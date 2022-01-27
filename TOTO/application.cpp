#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"

MainSDLWindow *wdw = new MainSDLWindow;
snake *sk = new snake;
fruit *fr = new fruit;
Uint32 frameStart, frameTime, frameDelay = 95;

void application::initGame(int width, int size)
{
  srand(time(0));

  score = 0;
  wdw->init(width, score);
  fr->initApple(size, sk->posX, sk->posY);
}


void application::deleteObject(void)
{
  delete wdw, sk, fr;
}



bool application::runGAme(int sizeOfSquare, int width, int size, bool done)
{
  frameStart = SDL_GetTicks();
  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, width, size);

  sk->drawHead(sizeOfSquare, wdw->getRenderer());
  fr->randomApple(sizeOfSquare, wdw->getRenderer());
  
  if (sk->isOnApple(fr->appleX, fr->appleY))
  {
    score += fr->newApple(sizeOfSquare, wdw->getRenderer(), size, sk->posX, sk->posY);
    getScore(score);
  }
  wdw->draw_number(score, 10, width+10);

  if (sk->collision(size)) 
  { 
    return true;
  }

  SDL_SetRenderDrawColor(wdw->getRenderer(), 0, 0, 0, 255);

  SDL_RenderPresent(wdw->getRenderer());

  SDL_UpdateWindowSurface(wdw->getWindow());
  sk->move();

  frameTime = SDL_GetTicks() - frameStart;
  if ( frameTime < frameDelay )
  {
    SDL_Delay( frameDelay - frameTime );
  }
  
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return true;
    }
  }
  
  return false;
}