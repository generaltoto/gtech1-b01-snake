#pragma once 
#include <SDL2/SDL.h>

class snake 
{
private: 

public:

  int dirX = 0, dirY = 0;

  int posX = 10, posY = 10;

  void move();

  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);

  bool isOnApple(int appleX, int appleY);

  bool collision(int rows);

};