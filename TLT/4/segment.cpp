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

void Segment::hfollow(int* nposX, int* nposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer){
  int exposX = posX;
  int exposY = posY;
  posX = *nposX;
  posY = *nposY;
  if(this->next == NULL){
    cout << "j'uis le 2ème en théorie" <<endl;
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
  cout << this->next << eat << endl;
  if (this->next == NULL && eat){
    cout << "g mangé donc je grandi" << endl;
    Segment *s = new Segment;
    this->next = s;
    s->init(exposX, exposY);  
  }else if(this->next !=NULL) {
    eat = false;
    this->next->follow(exposX, exposY, eat, sizeOfSquare, renderer);
  }
}
