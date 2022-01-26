#pragma once 
#include <SDL2/SDL.h>

class square
{
private:

  int dirX = 0, dirY = 0;

  int posX = 10, posY = 10;

  int appleX, appleY;

public:

  void move();

  void draw(int sizeOfSquare, SDL_Renderer *renderer);

  bool collision();

  void randomApple(int sizeOfSquare, SDL_Renderer *renderer);

  void initApple();

  int eatApple(int sizeOfSquare, SDL_Renderer *renderer);

};