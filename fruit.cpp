#include <iostream>
#include "fruit.hpp"
#include "snake.hpp"
#include "application.hpp"

void Fruit::initApple(int rows, int posX, int posY) {
  n = rand() % 2;
  std::cout << n << std::endl;

  appleR = 255, appleG = 0, appleB = 0;

  do { appleX = rand() % (rows-1) + 1; } while (appleX == posX);
  do { appleY = rand() % (rows-1) + 1; } while (appleY == posY);
}

void Fruit::rgbFruit(void)
{
  if (appleR == 255 && appleG < 255 && appleB == 0){
  appleG+=15;
  }
  else if (appleR > 0 && appleG == 255){
    appleR-=15;
  }
  else if (appleG == 255 && appleB < 255){
    appleB+=15;
  }
  else if (appleG > 0 && appleB == 255){
    appleG -=15;
  }
  else if (appleB == 255 && appleR < 255){
    appleR+=15;
  }
  else if (appleB > 0 && appleR == 255){
    appleB-=15;
  }
}

void Fruit::drawApple (int sizeOfSquare, SDL_Renderer *renderer) {
  if (n==0) { 
    rgbFruit(); 
  } else {
    appleR = 231;
    appleG = 71;
    appleB = 29;
  }

  SDL_SetRenderDrawColor(renderer, appleR, appleG, appleB, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect); 
}

int Fruit::newApple (int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY, int * score) {
  if (n != 0) { *score = *score + 1; }
  else { *score = *score + 2; }
  
  initApple(rows, posX, posY);
  drawApple(sizeOfSquare, renderer);
}