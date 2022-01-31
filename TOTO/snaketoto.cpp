#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>

#include "object.hpp"
using namespace std;



int main (void) 
{

  randomObject *rdm = new randomObject();

  int b;
  string myName;
  cout << "enter b value : ";
  cin >> b;
  rdm->a = b + 2;

  int result = rdm->add(b);
  cout << "a = " << rdm->a << "and b = " << b << "result = " << result << endl;

  return 0;
}