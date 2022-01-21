#include <SDL2/SDL.h>

class MainSDLWindow 
{
private:
  SDL_Window * window;
  SDL_Renderer * renderer;

public:
  MainSDLWindow () //called on when class called in main
  {
    window = NULL;
    renderer = NULL;
  }

  ~MainSDLWindow () //called at the end of main
  {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
  }

  void init (void) 
  {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_MINIMIZED);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    drawGrid(900, 20, 0);

    SDL_Delay(3000);   
    SDL_RenderPresent(renderer);

    SDL_Delay(8000);
  }

  void drawGrid (int width, int rows, int surface)
  {
    int sizeOfSquare = floor(width / rows);

    int x = 0;
    int y = 0;

    for (int l; l<rows; l++)
    {
      x += sizeOfSquare;
      y += sizeOfSquare;

      SDL_RenderDrawLine(renderer, x, y, x+width, y);
      SDL_RenderDrawLine(renderer, x, y, x, y+width);
    }
  }
};