#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "segment.hpp"

using namespace std;
  
Uint32 frameStart, frameTime, frameDelay = 70, iter = 0;
int score = 0;
bool play = true;

void Application::initWindow(){
  wdw = new MainSDLWindow;
  wdw->init(WIDTH);
}

void Application::initGame() {
  srand(time(0));

  color = 0;

  sk = new HSnake;
  fr = new Fruit;   
  s = new Segment;

  fr->initApple(GRID_SIZE, sk->posX, sk->posY); 
  sk->next = s;
}

void Application::deleteObject() {
  score = 0;
  delete sk, fr, s;
}

void Application::deleteWindow() {
  delete wdw;
}

bool Application::runGame(bool done) {
  bool eat = false;
  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);
  if (score >= 10 && color == 0) {
    wdw->gridColor(score);
    color = 1;
  } else if (score >= 20 && color == 1) {
    wdw->gridColor(score);
    color = 2;
  } else if (score >= 30 && color == 2) {
    wdw->gridColor(score);
    color = 3;
  }

  if (sk->isOnApple(fr->appleX, fr->appleY)) {
    fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY,&score);
    eat = true;
  }

  do {
    frameStart = SDL_GetTicks();
    sk->keyEnter();
    iter ++;                      
  } while (iter % frameDelay == 0);
  iter = 0;

  sk->move(eat, sizeOfSquare, wdw->getRenderer()); 

  if (!eat) { fr->drawApple(sizeOfSquare, wdw->getRenderer()); }
  
  sk->drawHead(sizeOfSquare, wdw->getRenderer());                                                     

  wdw->draw_number(score, 10, WIDTH+10);
  if(sk->hcollision(GRID_SIZE)) {
    return true;
  }

  frameTime = SDL_GetTicks() - frameStart;
  if ( frameTime < frameDelay ) {
		SDL_Delay( frameDelay - frameTime );
	}

  SDL_SetRenderDrawColor(wdw->getRenderer(), 0, 0, 0, 255);

  SDL_RenderPresent(wdw->getRenderer());

  SDL_UpdateWindowSurface(wdw->getWindow());
    
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
  int r = 0;

  do {
    SDL_Surface* image = SDL_LoadBMP("gameover.bmp");
    if(!image){
      cout << "Erreur de chargement de l'image : " << SDL_GetError() << endl;
      return false;
    }
    SDL_Texture* monImage = SDL_CreateTextureFromSurface(wdw->getRenderer(),image);
    SDL_QueryTexture(monImage, NULL, NULL, 0, 0);
    SDL_RenderCopy(wdw->getRenderer(), monImage, NULL, 0);
    SDL_RenderPresent(wdw->getRenderer());

    if(keystate[SDL_SCANCODE_RETURN]){
      SDL_RenderClear(wdw->getRenderer());
      return true;
    }

    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT || keystate[SDL_SCANCODE_ESCAPE]) {
        return false;
      }
    }
  } while(r ==0);

  return false;
}