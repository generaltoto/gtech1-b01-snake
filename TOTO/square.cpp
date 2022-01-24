#include "square.hpp"

#define WIDTH 900
#define GRID_SIZE 20

void cube::move()
{
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP]) {
    this->dirX = 0;
    this->dirY = 1; 
  }
  if (keystate[SDL_SCANCODE_DOWN]) {
    this->dirX = 0;
    this->dirY = -1; 
  }
  if (keystate[SDL_SCANCODE_LEFT]) {
    this->dirX = -1;
    this->dirY = 0; 
  }
  if (keystate[SDL_SCANCODE_RIGHT]) {
    this->dirX = 1;
    this->dirY = 0; 
  }

  posX += posX * dirX; //on augmente la position du cube dans la direction choisie
  posY += posY * dirY;
}

void cube::draw(int sizeOfSquare)
{
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare-1, sizeOfSquare-1 };
  SDL_RenderDrawRect(renderer, &rect);
}