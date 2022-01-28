#include <iostream>
#include "segment.hpp"
using namespace std;

void Segment::init(int nposX, int nposY){
  posX = nposX;
  posY = nposY;
}


void Segment::draw(int sizeOfSquare, SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { this->posX * sizeOfSquare, this->posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

void Segment::hfollow(int nposX, int nposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer){
  int exposX = posX;
  int exposY = posY;
  posX = *nposX;
  posY = *nposY;
  if(this->next == NULL){
    Segment *s = new Segment;
    this->next = s;
    s->init(exposX, exposY);
  }else if (this->next != NULL){
    this->next->follow(exposX, exposY, eat, sizeOfSquare, renderer);
  }
}

void Segment::follow(int nposX, int nposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer){
  int exposX = posX;
  int exposY = posY;
  posX = nposX;
  posY = nposY;
  this->draw(sizeOfSquare, renderer);
  if (next == NULL && eat){
    Segment *s = new Segment;
    this->next = s;
    s->init(exposX, exposY);  
  }else if(this->next !=NULL) {
    this->next->follow(exposX, exposY, eat, sizeOfSquare, renderer);
  }
}

bool Segment::collision(int hposX, int hposY){
  if(hposX == this->posX && hposY == this->posY){
    return true;
  }else if(next != NULL){
    return next->collision(hposX, hposY);  
  }else{
    return false;
  }
}
