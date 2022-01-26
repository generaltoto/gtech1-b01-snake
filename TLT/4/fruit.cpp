#include <iostream>
#include "fruit.hpp"
#include "snake.hpp"

void Fruit::initApple(int rows, int posX, int posY) {
  do { appleX = rand() % (rows-1) + 1; } while (appleX == posX);
  do { appleY = rand() % (rows-1) + 1; } while (appleY == posY);
}

void Fruit::randomApple (int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect); 
}

int Fruit::newApple (int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY) {
  initApple(rows, posX, posY);
  randomApple(sizeOfSquare, renderer);
  return 1;
}