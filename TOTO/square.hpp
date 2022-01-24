#pragma once 

#include <SDL2/SDL.h>

class square
{
private:

  int dirX = 0;
  int dirY = 0;

  int posX = 10;
  int posY = 10;

public:

  void draw(int sizeOfSquare, SDL_Renderer *renderer);

  void move ();

};