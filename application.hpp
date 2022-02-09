#pragma once 

#include <SDL2/SDL.h>
#include "snake.hpp"
#include "mainSDLWindow.hpp"
#include "fruit.hpp"

#define WIDTH 700
#define GRID_SIZE 25


class Application 
{
private:

  int score;
  int color;
  int n;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE);

public: 
  HSnake *sk;
  Fruit *fr;   
  Segment *s;
  MainSDLWindow *wdw;

  void rgbColor (int R, int G, int B);

  void initWindow();

  void initGame();

  bool runGame(bool done, bool *play);

  int getScore(int score);

  void deleteObject();

  void deleteWindow();

  bool replay();
};