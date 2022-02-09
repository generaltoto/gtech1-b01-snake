#pragma once

#include <SDL2/SDL.h>

class MainSDLWindow 
{
private:

  SDL_Window *window;
  SDL_Renderer *renderer;

public:

  int gridLightR = 170, gridLightG = 215, gridLightB = 81;
  int gridDarkR = 162, gridDarkG = 209, gridDarkB = 73;

  MainSDLWindow ()
  {
    window = NULL;
    renderer = NULL;
  }

  ~MainSDLWindow ()
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
  }

  SDL_Renderer *getRenderer(){ return renderer; }
  SDL_Window *getWindow(){ return window; }
  //function to get renderer and window in application.cpp

  int init (int width);
  //init window parameters 

  void drawWindow(int SizeOfSquare, int width, int size);
  //displaying window with grid 

  void gridColor(int score);
  //changing grid color every 10 points 

  void draw_digit(int digit, int posX, int posY );
  //displaying digits on a 3*5 grid 

  void draw_number( int number, int posX, int posY );
  //displaying numbers with 2 digits on 2 3*5 grid S
};