#include <SDL2/SDL.h>
#pragma once

class Square {  
  private:
    int X = 30;
    int Y = 30;
    //Segment* head;

  public:
    Square(){
    }

    void draw(int sizeOfSquare, SDL_Renderer * renderer);

    void move(int sizeOfSquare, bool axe);

    void eat();
};