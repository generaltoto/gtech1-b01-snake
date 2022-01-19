#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <stdlib.h>

#include "ex1.hpp"

using namespace std;


int main(void){
  MainSDLWindow main_window;
  main_window.Init("snake", 500, 500);
  SDL_Delay(3000);
}