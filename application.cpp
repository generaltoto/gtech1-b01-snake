#include <iostream>

#include "application.hpp"
#include "mainSDLWindow.hpp"
#include "snake.hpp"
#include "fruit.hpp"
#include "segment.hpp"

using namespace std;
  
Uint32 frameStart, frameTime, frameDelay = 70, iter = 0;

void Application::rgbColor (int R, int G, int B) 
{
  if (R == 255 && G < 255 && B == 0){
  G+=15;
  }
  else if (R > 0 && G == 255){
    R-=15;
  }
  else if (G == 255 && B < 255){
    B+=15;
  }
  else if (G > 0 && B == 255){
    G-=15;
  }
  else if (B == 255 && R < 255){
    R+=15;
  }
  else if (B > 0 && R == 255){
    B-=15;
  }

  fr->appleR = R; fr->appleG = G; fr->appleB = B;
  sk->headR = R; sk->headG = G; sk->headB = B;
}

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
  delete sk, fr, s;
}

void Application::deleteWindow() {
  delete wdw;
}

bool Application::runGame(bool done, bool *play) {
  bool eat = false;
  int exposX, exposY;
  SDL_RenderClear(wdw->getRenderer());

  wdw->drawWindow(sizeOfSquare, WIDTH, GRID_SIZE);
  if (score == 10 && color == 0) {
    wdw->gridColor(score);
    color = 1;
  } else if (score == 20 && color == 1) {
    wdw->gridColor(score);
    color = 2;
  } else if (score == 30 && color == 2) {
    wdw->gridColor(score);
    color = 3;
  }


  if (sk->isOnApple(fr->appleX, fr->appleY)) {
    score += 1;
    n = fr->newApple(sizeOfSquare, wdw->getRenderer(), GRID_SIZE, sk->posX, sk->posY);
    eat = true;
  }

  do {
    frameStart = SDL_GetTicks();
    sk->keyEnter(play);
    iter ++;                      
  } while (iter % frameDelay == 0);

  iter = 0;
  if (play){
    sk->move(eat, sizeOfSquare, wdw->getRenderer());
  } else {
  SDL_Surface* image = SDL_LoadBMP("gameover.bmp");
  SDL_Texture* monImage = SDL_CreateTextureFromSurface(wdw->getRenderer(),image);
  }


  if (n == 0) 
  {
    fr->fruitType = 1;
    rgbColor(fr->appleR, fr->appleG, fr->appleB);
    fr->drawRGBApple(sizeOfSquare, wdw->getRenderer());
  } 
  else
  {
    fr->fruitType = 0;
    fr->drawApple(sizeOfSquare, wdw->getRenderer());
  } 


  if (fr->fruitType == 1) 
  {
    rgbColor(sk->headR, sk->headG, sk->headB);
    sk->drawRGBHead(sizeOfSquare, wdw->getRenderer());
  } 
  else if (fr->fruitType == 0) 
  {
    sk->drawHead(sizeOfSquare, wdw->getRenderer());
  }

                                   

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
  int r = 0;

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