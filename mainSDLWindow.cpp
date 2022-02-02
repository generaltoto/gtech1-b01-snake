#include <iostream>
#include <string>

#include "mainSDLWindow.hpp"

static const char* zero  = "xxxx xx xx xxxx";
static const char* one   = "  x  x  x  x  x";
static const char* two   = "xxx  xxxxx  xxx";
static const char* three = "xxx  xxxx  xxxx";
static const char* four  = "x xx xxxx  x  x";
static const char* five  = "xxxx  xxx  xxxx";
static const char* six   = "xxxx  xxxx xxxx";
static const char* seven = "xxx  x  x  x  x";
static const char* eight = "xxxx xxxxx xxxx";
static const char* nine  = "xxxx xxxx  xxxx";

static const char** digits[] = { &zero, &one, &two, &three, &four, &five, &six, &seven, &eight, &nine };


int MainSDLWindow::init(int width, int score) {

  SDL_Init(SDL_INIT_VIDEO);

  std::string displayedText = std::__cxx11::to_string(score);

  window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, width + (width/10), SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if ( !renderer || !window ) {
    std::cout << "An error has occured, error code : " << SDL_GetError() << std::endl;
    return EXIT_FAILURE;
  } 
  return EXIT_SUCCESS;
}

void MainSDLWindow::drawWindow(int sizeOfSquare, int width, int size) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect rect = { 0, 0, width, width };
  SDL_RenderFillRect(renderer, &rect);

  SDL_SetRenderDrawColor(renderer, 69, 69, 69, SDL_ALPHA_OPAQUE);


  // vert clair : 170, 215, 81
  // vert foncé : 162, 209, 73

  for (int i=0; i<size; i++)
  {
    for (int j=0; j<size; j++)
    {
      if ((i+j)%2 == 0)
      {
        SDL_SetRenderDrawColor(renderer, 170, 215, 81, SDL_ALPHA_OPAQUE);
      } else 
      {
        SDL_SetRenderDrawColor(renderer, 162, 209, 73, SDL_ALPHA_OPAQUE);
      }
      SDL_Rect gridRect = { i * sizeOfSquare, j * sizeOfSquare, sizeOfSquare, sizeOfSquare };
      SDL_RenderFillRect(renderer, &gridRect);
    }
  }
}

void MainSDLWindow::draw_digit(int digit, int posX, int posY) {
	SDL_Rect rect = { 0, 0, 10, 10 };
	SDL_SetRenderDrawColor( renderer, 255, 255, 255, SDL_ALPHA_OPAQUE );

	digit = digit % 10;

	for ( int y = 0; y < 5; ++y ) {
		for ( int x = 0; x < 3; ++x ) {
			if ( (*(digits[digit]))[y * 3 + x] == 'x' ) {
				rect.x = posX + x * 10;
				rect.y = posY + y * 10;
				SDL_RenderFillRect( renderer, &rect );
			}
		}
	}
}

void MainSDLWindow::draw_number( int number, int posX, int posY ) {
	if ( number >= 100 ){ 
    return;
  }

	if ( number >= 10 ) {
		draw_digit( number % 10, posX + 40, posY );
		draw_digit( number / 10, posX, posY );
	}else {
		draw_digit( number, posX, posY );
	}
}