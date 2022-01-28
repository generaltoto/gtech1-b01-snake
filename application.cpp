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

  wdw->init(WIDTH, score);                                                //window init
  fr->initApple(GRID_SIZE, sk->posX, sk->posY);
  s->init(4, 5); 
  sk->next = s;
}

void Application::deleteObject(void)
{
  delete wdw, sk, fr, s;
}

bool Application::runGame(bool done){
  bool eat = false;
  frameStart = SDL_GetTicks();                                          //number of second since initialization
  SDL_RenderClear(wdw->getRenderer());                                  //clearing renderer

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);                      //disp grid

  sk->drawHead(sizeOfSquare, wdw->getRenderer());                       //disp squares
  s->draw(sizeOfSquare, wdw->getRenderer());                           
  fr->randomApple(sizeOfSquare, wdw->getRenderer());                     //random Apple position                   
    
  if (sk->isOnApple(fr->appleX, fr->appleY)) {
    score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);   //checking eat apple, score += 1 if so
    eat = true;
  }

  int exposX, exposY;
  sk->move(&exposX, &exposY);                         
  s->hfollow(&exposX, &exposY, eat, sizeOfSquare, wdw->getRenderer());

  wdw->draw_number(score, 10, WIDTH+10);
  if(sk->hcollision(GRID_SIZE)){
    return true;
  }                                      //checking for collisions

  SDL_SetRenderDrawColor(wdw->getRenderer(), 0, 0, 0, 255);

  SDL_RenderPresent(wdw->getRenderer());                                //disp everything on window

  SDL_UpdateWindowSurface(wdw->getWindow());                            //update window

  frameTime = SDL_GetTicks() - frameStart;                              //framerate managing 
  if ( frameTime < frameDelay ) {
		SDL_Delay( frameDelay - frameTime );
	}
    
  SDL_Event event;                                                      //checking for quit event
  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      return true;
    }
  }
  return false;
}