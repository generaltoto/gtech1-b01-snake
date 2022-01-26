#pragma once 
#include <SDL2/SDL.h>

class Segment {
private:
    
public:
  int posX = 0, posY = 0;
  
  void follow(int nposX, int nposY);

  void draw(int sizeOfSquare, SDL_Renderer *renderer);
};