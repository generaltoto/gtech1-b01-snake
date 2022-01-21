#include "mainSDLWindow.hpp"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <iostream>

int main (int argc, char *argv[])
{
  MainSDLWindow *wdw = new MainSDLWindow;
  wdw->init();

  return 0;
}