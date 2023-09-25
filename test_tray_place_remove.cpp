#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Tray.h"

using namespace std;

#if __has_include("memory_replacement.h")
#include "memory_replacement.h"
#endif

int main()
{
  Egg smaller(1.24);
  Egg peewee(1.25);
  Egg small(1.5);
  Egg medium(1.75);
  Egg large(2.0);
  Egg xlarge(2.25);
  Egg jumbo(2.5);

  Tray troy;
  cout << "Printing an empty tray:\n";
  cout << troy;
  troy.place_back(smaller);
  troy.place_back(peewee);
  troy.place_back(small);
  troy.place_back(medium);
  troy.place_back(large);
  troy.place_back(xlarge);
  troy.place_back(jumbo);
  cout << "Pushed back one of each:\n";
  cout << troy;
  troy.remove(small);
  troy.remove(medium);
  troy.remove(large);
  cout << "Removed small, medium, and large:\n";
  cout << troy;

  Tray another;
  cout << "\n\nStarting again:\n" << another;
  another.remove(jumbo);
  cout << "Called remove(). Should still be empty:\n" << another;
  another.place_front(jumbo);
  another.place_front(jumbo);
  another.place_front(small);
  another.place_front(jumbo);
  another.place_front(jumbo);
  cout << "After 5 place_front() calls:\n" << another;
  another.remove(jumbo);
  cout << "After remove(jumbo):\n" << another;
  another.remove(jumbo);
  cout << "Again remove(jumbo), should be no change:\n" << another;
  return 0;
}
