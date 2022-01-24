#include <SDL2/SDL.h>
#pragma once

class Square {  
  private:
    int dirX = 1;
    int dirY = 0;
    int posX = 10;
    int posY = 10;
    //Segment* head;

  public:
    Square(){
    }

    void draw(int sizeOfSquare, SDL_Renderer * renderer);

    void move();

    void eat();
};