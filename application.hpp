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

  int color;
  int sizeOfSquare = floor(WIDTH / GRID_SIZE);

public: 
  HSnake *sk;
  Fruit *fr;   
  Segment *s;
  MainSDLWindow *wdw;

  void initWindow(); 
  //Window Init 

  void initGame(); 
  //Game init 

  bool runGame(bool done); 
  //Game mechanic

  void deleteObject(); 
  //clearing all objects for memory

  void deleteWindow(); 
  //clearing window on quit

  bool replay(); 
  //allowing player to replay
};