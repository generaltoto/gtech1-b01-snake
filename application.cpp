#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "segment.hpp"

using namespace std;
  
MainSDLWindow *wdw = new MainSDLWindow;
HSnake *sk = new HSnake;
Fruit *fr = new Fruit;   
Segment *s = new Segment;
Uint32 frameStart, frameTime, frameDelay = 70, iter = 0; 

void Application::initGame(void) {
  score = 0;
  srand(time(0));

  wdw->init(WIDTH, score);
  fr->initApple(GRID_SIZE, sk->posX, sk->posY); 
  sk->next = s;
}

void Application::deleteObject(void) {
  delete sk, fr, s;
}

void Application::deleteWindow(void) {
  delete wdw;
}

bool Application::runGame(bool done) {
  bool eat = false;
  int exposX, exposY;
  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);

  if (sk->isOnApple(fr->appleX, fr->appleY)) {
    score += fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);
    eat = true;
  }

  do {
    frameStart = SDL_GetTicks();
    sk->keyEnter();
    iter ++;                      
  } while (iter % frameDelay == 0);

  iter = 0;
  sk->move(eat, sizeOfSquare, wdw->getRenderer());
  sk->drawHead(sizeOfSquare, wdw->getRenderer());                        
  fr->randomApple(sizeOfSquare, wdw->getRenderer());             

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

bool Application::replay(){
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  SDL_Surface* image = SDL_LoadBMP("gameover.bmp");
  SDL_Texture* monImage = SDL_CreateTextureFromSurface(wdw->getRenderer(),image);
  SDL_RenderPresent(wdw->getRenderer());
  cout << "j'uis arrivé là" << endl;
  return true;
  /*while(r == 0){
    cout << "boucle" << endl;
    if (keystate[SDL_SCANCODE_RETURN]){
      cout << "true" << endl;
      r = 1;
      return true;
    }else if (keystate[SDL_SCANCODE_ESCAPE]){
      cout << "false" << endl;
      r = 1;
      return false;
    }
  }*/
}