#pragma once 
#include <SDL2/SDL.h>
#include "segment.hpp"

class HSnake  {
private: 

public:

  int dirX = 0, dirY = 0;

  int posX = 10, posY = 10;

  Segment * next = new Segment;

  int move();

  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);

  bool isOnApple(int appleX, int appleY);

  bool collision(int rows);

};