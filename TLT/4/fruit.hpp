#pragma once 
#include <SDL2/SDL.h>

class Fruit {
private:

public:

  int appleX, appleY;

  void randomApple(int sizeOfSquare, SDL_Renderer *renderer);

  void initApple(int rows, int posX, int posY);

  int newApple(int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY);

  bool isOnApple (void);
};