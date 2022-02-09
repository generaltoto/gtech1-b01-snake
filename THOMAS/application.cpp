#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"

MainSDLWindow *wdw = new MainSDLWindow;
snake *sk = new snake;
fruit *fr = new fruit;
Uint32 frameStart, frameTime, frameDelay = 70;

void application::initGame(void)
{
  srand(time(0));

  score = 0;
  wdw->init(WIDTH, score);
  fr->initApple(GRID_SIZE, sk->posX, sk->posY);
}


void application::deleteObject(void)
{
  delete wdw, sk, fr;
}



bool application::runGAme(bool done)
{
  frameStart = SDL_GetTicks();

  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);

  sk->drawHead(sizeOfSquare, wdw->getRenderer());

  fr->randomApple(sizeOfSquare, wdw->getRenderer());
  
  if (sk->isOnApple(fr->appleX, fr->appleY))
  {
    score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);
  }
  wdw->draw_number(score, 10, WIDTH+10);

  if (sk->collision(GRID_SIZE)) 
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