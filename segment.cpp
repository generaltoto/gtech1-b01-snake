#include "segment.hpp"

void Segment::init(int nposX, int nposY) 
{
  posX = nposX;
  posY = nposY;
}

void Segment::drawSegment(int sizeOfSquare, SDL_Renderer *renderer) 
{
  SDL_SetRenderDrawColor(renderer, 70, 115, 232, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { this->posX * sizeOfSquare, this->posY * sizeOfSquare, sizeOfSquare, sizeOfSquare };
  SDL_RenderFillRect(renderer, &rect);
}

void Segment::follow(int nposX, int nposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer) 
{
  int exposX = posX;
  int exposY = posY;
  posX = nposX;
  posY = nposY;
  this->drawSegment(sizeOfSquare, renderer);
  if (next == NULL && eat){
    Segment *s = new Segment;
    this->next = s;
    s->init(exposX, exposY);  
  }
  else if(this->next !=NULL) {
    this->next->follow(exposX, exposY, eat, sizeOfSquare, renderer);
  }
}

bool Segment::collision(int hposX, int hposY) 
{
  if(hposX == this->posX && hposY == this->posY) {
    return true;
  }
  else if(next != NULL) {
    return next->collision(hposX, hposY);  
  }
  else {
    return false;
  }
}
