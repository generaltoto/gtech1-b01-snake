#include "square.hpp"
#include <iostream>
using namespace std;

#define WIDTH 900
#define GRID_SIZE 20

void Square::move(int sizeOfSquare) {
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP]) {
    this->Y -= sizeOfSquare;
  }
  if (keystate[SDL_SCANCODE_DOWN]) {
    this->Y += sizeOfSquare;
  }
  if (keystate[SDL_SCANCODE_LEFT]) {
    this->X  -= sizeOfSquare;
  }
  if (keystate[SDL_SCANCODE_RIGHT]) {
    this->X += sizeOfSquare; 
  }
}

void Square::draw(int sizeOfSquare,SDL_Renderer * renderer) {
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { this->X, this->Y, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
  SDL_RenderPresent(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void Square::eat() {

}