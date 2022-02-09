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
  //Moving snake and following segments

  void keyEnter();
  //checking for keyboard key press

  void drawHead(int sizeOfSquare, SDL_Renderer *renderer);
  //drawing the snake's head

  bool isOnApple(int appleX, int appleY);
  //checking is the snake is eating the apple

  bool hcollision(int rows);
  //checking is the snake is hitting a wall

};