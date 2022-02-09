#pragma once 
#include <SDL2/SDL.h>

class Fruit {
private:

public:

  int appleX, appleY;

  int fruitType;
  int appleR = 255, appleG = 0, appleB = 0;

  void initApple(int rows, int posX, int posY);

  void drawRGBApple (int sizeOfSquare, SDL_Renderer *renderer);
  void drawApple(int sizeOfSquare, SDL_Renderer *renderer);

  int newApple(int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY);

  bool isOnApple (void);
};