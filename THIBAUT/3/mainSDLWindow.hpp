#include <SDL2/SDL.h>
#pragma once

class MainSDLWindow {
  private:
    SDL_Window * window;
    SDL_Renderer * renderer;
  
  public:
    MainSDLWindow () {
      window = NULL;
      renderer = NULL;
    }

    ~MainSDLWindow () {
      SDL_DestroyWindow(window);
      SDL_DestroyRenderer(renderer);
      SDL_Quit();
    }

    int init (int width);

    //void draw(int SizeOfSquare, int width, int size);

    SDL_Renderer * getRenderer(){
      return renderer;
    }
    SDL_Window *getWindow(){ 
      return window; 
    }
};