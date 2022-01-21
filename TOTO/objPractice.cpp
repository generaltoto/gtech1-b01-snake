#include <stdio.h>
#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

class randomObject 
{
private:
  int c, l;

public: 
  int a;
  int add(int b)
  {
    return this->a+b;
  }
  int move(int horiz, int vert)
  {
    this-> c += horiz;
    this-> l += vert;
  }
};

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