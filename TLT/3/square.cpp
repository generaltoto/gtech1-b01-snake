#include "square.hpp"
#include "fruit.hpp"
#include <iostream>
using namespace std;

#define WIDTH 700
#define GRID_SIZE 20

void Square::move(int sizeOfSquare, bool axe) {
  const Uint8 *keystate = SDL_GetKeyboardState(NULL);

  if (keystate[SDL_SCANCODE_UP]) {
    this->dirX = 0;
    this->dirY = -1; 
  }
  if (keystate[SDL_SCANCODE_DOWN]) {
    this->dirX = 0;
    this->dirY = 1; 
  }
  if (keystate[SDL_SCANCODE_LEFT]) {
    this->dirX = -1;
    this->dirY = 0; 
  }
  if (keystate[SDL_SCANCODE_RIGHT]) {
    this->dirX = 1;
    this->dirY = 0; 
  }
    this->posX += this->dirX; //on augmente la position du cube dans la direction choisie
    this->posY += this->dirY;
}

void Square::draw(int sizeOfSquare,SDL_Renderer * renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { this->posX * sizeOfSquare, this->posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

bool Square::collision(int rows){
  if (this->posX <0 || this->posX >= rows-1 || this->posY < 0 || this->posY >= rows-1){ return true; } 
  return false;
}

bool Square::isOnApple(int appleX, int appleY){
  if (appleX == this->posX && appleY == this->posY) { return true; }
  else { return false; }
}

int Square::getPos(){
  return this->posX, posY;
}

int Square::getDir(){
  return this->dirX, dirY;
}