#include <iostream>
using namespace std;
#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20

void square::move()
{
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_W]) {
    this->dirX = 0;
    this->dirY = -1; 
  }
  if (keystate[SDL_SCANCODE_S]) {
    this->dirX = 0;
    this->dirY = 1; 
  }
  if (keystate[SDL_SCANCODE_A]) {
    this->dirX = -1;
    this->dirY = 0; 
  }
  if (keystate[SDL_SCANCODE_D]) {
    this->dirX = 1;
    this->dirY = 0; 
  }

  posX += dirX; //on augmente la position du cube dans la direction choisie
  posY += dirY;
}



void square::draw(int sizeOfSquare, SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}



bool square::collision()
{
  if (posX <=0 || posX >= 20){ return true; } 
  else if (posY <= 0 || posY >= 20) { return true; }
  else { return false; }
}



void square::initApple()
{
  appleX = rand() % 19 + 1;
  while (appleX == posX) { appleX = rand() % 19 + 1; }

  appleY = rand() % 19 + 1;
  while (appleY == posY) { appleY = rand() % 19 + 1; }
}



void square::randomApple (int sizeOfSquare, SDL_Renderer *renderer)
{
  SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { appleX * sizeOfSquare, appleY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect); 
}



void square::eatApple (int sizeOfSquare, SDL_Renderer *renderer)
{
  if (appleX == posX && appleY == posY) {
    initApple();
    randomApple(sizeOfSquare, renderer);
    bool appleEaten = true; 
  } else { bool appleEaten = false; }
}