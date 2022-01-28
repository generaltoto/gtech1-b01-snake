#pragma once 
#include <SDL2/SDL.h>

class Segment {
private:
    
public:
  int posX = 0, posY = 0;

  Segment * next = NULL;

  Segment(){}

  void init(int nposX, int nposY);
  
  void follow(int exposX, int exposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer);

  bool collision(int hposX, int hposY);

  void draw(int sizeOfSquare, SDL_Renderer *renderer);
};