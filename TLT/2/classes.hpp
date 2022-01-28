#include <SDL2/SDL.h>

class MainSDLWindow 
{
private:
  SDL_Window * window;
  SDL_Renderer * renderer;

public:

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

  void init (void) 
  {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_MINIMIZED);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  }

  int drawGrid (int width, int rows)
  {
    int sizeOfSquare = floor(width / rows);

    int x = 0;
    int y = 0;

    for (int n; n<rows; n++)
    {
      x += sizeOfSquare;
      y += sizeOfSquare;

      SDL_RenderDrawLine(renderer, 0, y, width, y);
      SDL_RenderDrawLine(renderer, x, 0, x, width);
    }
    return sizeOfSquare;
  }

  int redraw(void)
  {
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_Rect rect = { 0, 0, 900, 900 };
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    int sizeOfSquare = drawGrid(900, 20);
   
    SDL_RenderPresent(renderer);

    SDL_Delay(20);
    return sizeOfSquare;
  }
};

/*
class Snake {
  private:
    SDL_Rect * rect;
    int size = floor(900 / 20);

  public:
    Snake() {
      rect.x = 0;
      rect.y = 0;
      rect.w = size;
      rect.h = size;
    }

    ~Snake() {

    }

    void head(SDL_Window * window, SDL_Renderer * renderer){
      SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawRect(renderer, rect);
    }
}*/