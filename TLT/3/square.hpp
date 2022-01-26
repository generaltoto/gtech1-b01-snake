#include <SDL2/SDL.h>
#pragma once

class Square {  
  private:
    int X = 0;
    int Y = 0;
    //Segment* head;

  public:
    Square(){
    }

    void draw(int sizeOfSquare, SDL_Renderer * renderer);

    void move(int sizeOfSquare);

    void eat();
};