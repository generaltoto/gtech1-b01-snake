#include <iostream>
#include "snake.hpp"
#include "fruit.hpp"

using namespace std;

int HSnake::move() {
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

  int exposX = posX;
  int exposY = posY;

  posX += dirX; //on augmente la position du cube dans la direction choisie
  posY += dirY;
  
  cout << exposX << exposY << endl;
  return exposX, exposY;
}

void HSnake::drawHead(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { posX * sizeOfSquare, posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

bool HSnake::collision(int rows) {
  if (posX <0 || posX >= rows || posY < 0 || posY >= rows){ 
    return true; 
  } 
  return false;
}

bool HSnake::isOnApple(int appleX, int appleY) {
  if (appleX == posX && appleY == posY) { 
    return true; 
  } else { 
    return false; 
  }
}
