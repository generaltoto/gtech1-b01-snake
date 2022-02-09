#pragma once 
#include <SDL2/SDL.h>

class Segment {
private:
    
public:
  int posX = 0, posY = 0;

  int segmentR, segmentG, segmentB;

  Segment * next = NULL;

  Segment(){}

  void init(int nposX, int nposY); 
  //creating segment, following the one before him
  
  void follow(int exposX, int exposY, bool eat, int sizeOfSquare, SDL_Renderer *renderer); 
  //giving previous coordinates to the following segment, making them follow each other

  bool collision(int hposX, int hposY);
  //checking collisions between head and segment

  void drawSegment(int sizeOfSquare, SDL_Renderer *renderer);
  //display segment
};