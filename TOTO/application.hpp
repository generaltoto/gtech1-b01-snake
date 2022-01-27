#pragma once 

#include <SDL2/SDL.h>


class application 
{
private:

  int score;

public: 

  void initGame(int width, int size);

  bool runGAme(int sizeOfSquare, int width, int size, bool done);

  int getScore(int score);

  void deleteObject(void);
};