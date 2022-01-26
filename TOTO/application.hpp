#pragma once 

#include <SDL2/SDL.h>


class application 
{
public: 

  void initGame(int width, int size, int score);

  bool runGAme(int sizeOfSquare, int width, int size, int score, bool done);
};