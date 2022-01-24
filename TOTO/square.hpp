#include <SDL2/SDL.h>

class cube
{
private:

  SDL_Renderer *renderer;

  int dirX = 1;
  int dirY = 0;

  int posX = 10;
  int posY = 10;

public:

  void draw(int sizeOfSquare);

  void move ();

};