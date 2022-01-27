#include <iostream>
#include "segment.hpp"

void Segment::init(int nposX, int nposY){
  posX = nposX;
  posY = nposY;
}


void Segment::draw(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { this->posX * sizeOfSquare, this->posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

void Segment::follow(int nposX, int nposY){
  /*int exposX = posX;
  int exposY = posY;*/
  posX = nposX;
  posY = nposY;
  /*if (this->next){
    this->next->follow(exposX, exposY);
  }*/
}
