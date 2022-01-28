#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "segment.hpp"
  
MainSDLWindow *wdw = new MainSDLWindow;
HSnake *sk = new HSnake;
Fruit *fr = new Fruit;   
Segment *s = new Segment;
Uint32 frameStart, frameTime, frameDelay = 80; 

void Application::initGame(void) {
  score = 0;
  srand(time(0));

  wdw->init(WIDTH, score);
  fr->initApple(GRID_SIZE, sk->posX, sk->posY); 
  sk->next = s;
}

void Application::deleteObject(void) {
  delete wdw, sk, fr, s;
}

bool Application::runGame(bool done) {
  bool eat = false;
  frameStart = SDL_GetTicks();
  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);

  sk->drawHead(sizeOfSquare, wdw->getRenderer());                        
  fr->randomApple(sizeOfSquare, wdw->getRenderer());             
    
  if (sk->isOnApple(fr->appleX, fr->appleY)) {
    score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);
    eat = true;
  }

  int exposX, exposY;
  sk->move(&exposX, &exposY);                         
  s->follow(exposX, exposY, eat, sizeOfSquare, wdw->getRenderer());

  wdw->draw_number(score, 10, WIDTH+10);
  if(sk->hcollision(GRID_SIZE)) {
    return true;
  }

  SDL_SetRenderDrawColor(wdw->getRenderer(), 0, 0, 0, 255);

  SDL_RenderPresent(wdw->getRenderer());

  SDL_UpdateWindowSurface(wdw->getWindow());

  frameTime = SDL_GetTicks() - frameStart;
  if ( frameTime < frameDelay ) {
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