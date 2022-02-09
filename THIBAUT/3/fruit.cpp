#include <iostream>
#include "fruit.hpp"
#include "square.hpp"

void fruit::initApple(int rows, int posX, int posY) {
  do { appleX = rand() % (rows-1) + 1; } while (appleX == posX);
  do { appleY = rand() % (rows-1) + 1; } while (appleY == posY);
}

void fruit::randomApple (int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect); 
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

int fruit::newApple (int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY){
  initApple(rows, posX, posY);
  randomApple(sizeOfSquare, renderer);
  return 1;
}