#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

#include "exercice1.hpp"

int main(void) {
    MainSDLWindow main_window;
    main_window.init("snake", 500, 500);
    SDL_Delay(3000);
}