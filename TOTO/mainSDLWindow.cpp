#include <iostream>
#include <string>

#include "mainSDLWindow.hpp"
#include "square.hpp"

int MainSDLWindow::init(int width, int score) //réupération de width avec define dans =main.cpp=
{
  SDL_Init(SDL_INIT_VIDEO);
  TTF_Init();

  std::string displayedText = std::__cxx11::to_string(score);

  window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, width, SDL_WINDOW_MINIMIZED);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  font = TTF_OpenFont("Times.ttf", 50);
  //scoreSurface = TTF_RenderText_Solid(font,"9", color);
  //scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

  if ( !renderer || !window )
  {
    std::cout << "An error has occured, error code : " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  } 
  return EXIT_SUCCESS;
}


void MainSDLWindow::drawWindow(int sizeOfSquare, int width, int size) //recupération arguments dans =main.cpp=
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { 0, 0, width, width }; //define WIDTH dans =main.cpp=
  SDL_RenderFillRect(renderer, &rect);

  SDL_SetRenderDrawColor(renderer, 69, 69, 69, SDL_ALPHA_OPAQUE);

  //drawing grid
  int x = 0, y = 0;

  for (int n; n<size; n++) // n takes values from 0 to GRID_SIZE 
  {
    x += sizeOfSquare;
    y += sizeOfSquare;

    SDL_RenderDrawLine(renderer, 0, y, width, y);
    SDL_RenderDrawLine(renderer, x, 0, x, width);
  }  
}