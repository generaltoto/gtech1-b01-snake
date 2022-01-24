#include "mainSDLWindow.hpp"
#include "cube.hpp"

int MainSDLWindow::init(int width) //réupération de width avec define dans =main.cpp=
{
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, width, SDL_WINDOW_MINIMIZED);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


int MainSDLWindow::redraw(int sizeOfSquare, int width, int size) //recupération arguments dans =main.cpp=
{
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { 0, 0, width, width }; //define WIDTH dans =main.cpp=
  SDL_RenderFillRect(renderer, &rect);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  drawGrid(sizeOfSquare, width, size); //appel drawGrid dans =mainSDLWindow.cpp=

  cube *c = new cube;
  c->draw(sizeOfSquare); //dessin du cube depuis =cube.pp= fonction =draw()=
  
  SDL_RenderPresent(renderer);

  SDL_Delay(20);
}


int MainSDLWindow::drawGrid(int sizeOfSquare, int width, int size) //arguments découlent de redraw dans =mainSDLWidow.cpp=
{
  int x = 0;
  int y = 0;

  for (int n; n<size; n++) //on balaye le nombre de colonnes 
  {
    x += sizeOfSquare;
    y += sizeOfSquare;

    SDL_RenderDrawLine(renderer, 0, y, width, y);
    SDL_RenderDrawLine(renderer, x, 0, x, width);

  }
  return sizeOfSquare;
}