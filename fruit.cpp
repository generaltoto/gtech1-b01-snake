#include <iostream>
#include "fruit.hpp"
#include "snake.hpp"
#include "application.hpp"

void Fruit::initApple(int rows, int posX, int posY) {
  do { appleX = rand() % (rows-1) + 1; } while (appleX == posX);
  do { appleY = rand() % (rows-1) + 1; } while (appleY == posY);
}

void Fruit::drawRGBApple (int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, appleR, appleG, appleB, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect); 
}

void Fruit::drawApple(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 231, 71, 29, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

int Fruit::newApple (int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY) {
  initApple(rows, posX, posY);

  int n = rand() % 5;

  return n;
}