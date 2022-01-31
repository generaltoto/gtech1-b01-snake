#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

using namespace std;

void HSnake::move(int* exposX, int*exposY) {
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

  *exposX = posX;
  *exposY = posY;

  posX += dirX; 
  posY += dirY;
}

void HSnake::drawHead(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 190, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

bool HSnake::hcollision(int rows) {
  if (posX <0 || posX >= rows+1 || posY < 0 || posY >= rows+1){ 
    return true; 
  }
  return this->next->collision(posX, posY);
}

bool HSnake::isOnApple(int appleX, int appleY) {
  if (appleX == posX && appleY == posY) { 
    return true; 
  }else { 
    return false; 
  }
}
