#pragma once 
#include <SDL2/SDL.h>
#include "segment.hpp"

class HSnake  {
private: 

public:

  int dirX = 1, dirY = 0;

  int posX = 5, posY = 5;

  Segment * next = NULL;

  void move(int* exposX, int*exposY);

  void keyEnter();

  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);

  bool isOnApple(int appleX, int appleY);

  bool hcollision(int rows);

};