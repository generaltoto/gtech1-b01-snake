#include <SDL2/SDL.h>
#include <iostream>

int init (void) 
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 750, 600, SDL_WINDOW_MINIMIZED);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  SDL_SetRenderDrawColor(renderer, 18, 23, 28, 20); //set renderer color 

  SDL_RenderClear(renderer);                        //update the window and 'add' the renderer to it
  SDL_RenderPresent(renderer);                      //not sure

  SDL_Delay(3000);                                  //3sec delay
}

int main (int argc, char *argv[])
{
  init();

  return 0;
}