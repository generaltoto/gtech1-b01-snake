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

  int init (int width);

  int redraw(int SizeOfSquare, int width, int size);

  int drawGrid (int SizeOfSquare, int width, int size);
};