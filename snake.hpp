#pragma once 
#include <SDL2/SDL.h>
#include "segment.hpp"

class HSnake  {

public:

  int dirX = 1, dirY = 0;

  int headR, headG, headB;

  int posX = 5, posY = 5;

  Segment * next = NULL;

  void move(bool eat, int sizeOfSquare, SDL_Renderer *renderer);

  void keyEnter(bool *play);

  void drawRGBHead(int sizeOfSquare, SDL_Renderer *renderer);
  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);

  bool isOnApple(int appleX, int appleY);

  bool hcollision(int rows);

};