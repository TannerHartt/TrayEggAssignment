#include <iostream>
using namespace std;
#include"Egg.h"

// check that header guards were used.


int main()
{
  using std::cout;
  Egg should_be_zero_weight; //default ctor, test whether weight set to zero
  Egg should_be_another_error_weight(1.24);
  Egg peewee1(1.25);
  Egg peewee2(1.49);

  Egg small1(1.50);
  Egg small2(1.74);

  Egg medium1(1.75);
  Egg medium2(1.99);

  Egg large1(2.00);
  Egg large2(2.24);

  Egg extralg1(2.25);
  Egg extralg2(2.49);

  Egg jumbo1(2.50);
  Egg jumbo2(3.00);

  cout << "Errors:\n";
  cout << "  =->" << should_be_zero_weight << "<-=\n";
  cout << "  =->" << should_be_another_error_weight << "<-=\n";
  cout << "Peewee:\n";
  cout << "  =->" << peewee1 << "<-=\n";
  cout << "  =->" << peewee2 << "<-=\n";
  cout << "Small:\n";
  cout << "  =->" << small1 << "<-=\n";
  cout << "  =->" << small2 << "<-=\n";
  cout << "Medium:\n";
  cout << "  =->" << medium1 << "<-=\n";
  cout << "  =->" << medium2 << "<-=\n";
  cout << "Large:\n";
  cout << "  =->" << large1 << "<-=\n";
  cout << "  =->" << large2 << "<-=\n";
  cout << "Extra-Large:\n";
  cout << "  =->" << extralg1 << "<-=\n";
  cout << "  =->" << extralg2 << "<-=\n";
  cout << "Jumbo:\n";
  cout << "  =->" << jumbo1 << "<-=\n";
  cout << "  =->" << jumbo2 << "<-=\n";
  return 0;
}

