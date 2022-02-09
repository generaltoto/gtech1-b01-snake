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

  void initWindow(void); 
  //Window Init 

  void initGame(void); 
  //Game init 

  bool runGame(bool done); 
  //Game mechanic

  void deleteObject(void); 
  //clearing all objects for memory

  void deleteWindow(void); 
  //clearing window on quit

  bool replay(void); 
  //allowing player to replay
};