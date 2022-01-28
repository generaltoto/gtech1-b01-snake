#pragma once 
#include <SDL2/SDL.h>
#include "segment.hpp"

class HSnake  {
private: 

public:

  int dirX = 1, dirY = 0;

  int posX = 10, posY = 10;

  Segment * next = NULL;

  int move(int* exposX, int*exposY);

  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);

  bool isOnApple(int appleX, int appleY);

  bool hcollision(int rows);

};