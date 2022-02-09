#pragma once 
#include <SDL2/SDL.h>

class Fruit {
private:

public:

  int appleX, appleY;

  int appleR = 255, appleG = 0, appleB = 0;

  int n;

  void initApple(int rows, int posX, int posY);

  void rgbFruit(void);

  void drawApple(int sizeOfSquare, SDL_Renderer *renderer);

  int newApple(int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY, int * score);

  bool isOnApple (void);
};