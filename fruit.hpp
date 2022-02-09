#pragma once 
#include <SDL2/SDL.h>

class Fruit {
private:

public:

  int appleX, appleY;

  int appleR = 255, appleG = 0, appleB = 0;

  int n;

  void initApple(int rows, int posX, int posY);
  //init of apple coordinates and 1/8 chance to spacial apple

  void rgbFruit(void);
  //function for rgb colors

  void drawApple(int sizeOfSquare, SDL_Renderer *renderer);
  //displaying apple 

  void newApple(int sizeOfSquare, SDL_Renderer *renderer, int rows, int posX, int posY, int * score); 
  //coming from NewApple, creates a new apple
};