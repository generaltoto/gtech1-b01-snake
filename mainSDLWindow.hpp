#pragma once

#include <SDL2/SDL.h>

class MainSDLWindow {
private:
  SDL_Window *window;
  SDL_Renderer *renderer;

public:

  int gridLightR = 170, gridLightG = 215, gridLightB = 81;
  int gridDarkR = 162, gridDarkG = 209, gridDarkB = 73;

  MainSDLWindow () {
    window = NULL;
    renderer = NULL;
  }

  ~MainSDLWindow () {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
  }

  SDL_Renderer *getRenderer(){ return renderer; }
  SDL_Window *getWindow(){ return window; }

  int init (int width);

  void drawWindow(int SizeOfSquare, int width, int size);

  void gridColor(int score);

  void draw_digit(int digit, int posX, int posY );

  void draw_number( int number, int posX, int posY );

};