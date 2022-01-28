#include <SDL2/SDL.h>
#pragma once

class Square {  
  private:
    int dirX, dirY = 0;

    int posX, posY = 10;
    //Segment* head;

  public:
    Square(){
    }

    void draw(int sizeOfSquare, SDL_Renderer * renderer);

    void move(int sizeOfSquare, bool axe);

    bool collision(int rows);

    bool isOnApple(int appleX, int appleY);

    int getPos();

    int getDir();
};