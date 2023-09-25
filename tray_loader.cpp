#include<iostream>
using namespace std;

#include<cstdlib>
#include<ctime>
#include "Tray.h"
#include "Egg.h"
//confirm header guards were used


#if __has_include("instructors_rand.cpp")
#include "instructors_rand.cpp"
#include "memory_replacement.cpp"
#endif
int main()
{
  std::srand(time(NULL));

  for(int tray=0; tray<10; ++tray)
  {
    Tray t;
    for(int egg=0; egg<=tray; ++egg)
    {
      float weight=rand()%150/100.0+1.25;
      Egg e(weight);
      t.place_back(e);
    }
    cout << t << endl;
  }
  return 0;
}
