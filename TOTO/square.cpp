#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20

void square::move()
{
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_Z]) {
    this->dirX = 0;
    this->dirY = -1; 
  }
  if (keystate[SDL_SCANCODE_S]) {
    this->dirX = 0;
    this->dirY = 1; 
  }
  if (keystate[SDL_SCANCODE_Q]) {
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
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare-1, sizeOfSquare-1 };
  SDL_RenderFillRect(renderer, &rect);
}