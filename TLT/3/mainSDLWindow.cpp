#include <iostream>
using namespace std;

#include "mainSDLWindow.hpp"
#include "square.hpp"

int MainSDLWindow::init(int width) { //réupération de width avec define dans =main.cpp=
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
   printf("Erreur d'initialisation de la SDL : %s\n",SDL_GetError());//on affiche l'erreur
   return EXIT_FAILURE;//on sort du programme pour éviter de plus gros problèmes
}
  window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, width, SDL_WINDOW_MINIMIZED);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if ( !renderer || !window ) {
    cout << "An error has occured, error code : " << SDL_GetError() << endl;
    return EXIT_FAILURE;
  }else { 
    return EXIT_SUCCESS; 
  }
}

/*void MainSDLWindow::draw(int sizeOfSquare, int width, int size){ //recupération arguments dans =main.cpp= 
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { 0, 0, width, width }; //define WIDTH dans =main.cpp=
  SDL_RenderFillRect(renderer, &rect);

  SDL_SetRenderDrawColor(renderer, 69, 69, 69, SDL_ALPHA_OPAQUE);

  //drawing grid
  int x = 0, y = 0;

  for (int n; n<size; n++){ // n takes values from 0 to GRID_SIZE 
    x += sizeOfSquare;
    y += sizeOfSquare;

    SDL_RenderDrawLine(renderer, 0, y, width, y);
    SDL_RenderDrawLine(renderer, x, 0, x, width);
  }
}*/