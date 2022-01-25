#pragma once 
#include <SDL2/SDL.h>

class square
{
private:

  int dirX = 0, dirY = 0;

  int posX = 10, posY = 10;

  int appleX, appleY;

public:

  void draw(int sizeOfSquare, SDL_Renderer *renderer);

  void move();

  bool collision();

  void randomApple(int sizeOfSquare, SDL_Renderer *renderer);

  void initApple();

  void eatApple(int sizeOfSquare, SDL_Renderer *renderer);

};