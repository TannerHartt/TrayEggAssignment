#ifndef INSTRUMENTH
#define INSTRUMENTH

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Instrument {
protected:
	string instrumentName;
	string instrumentManufacturer;
	int yearBuilt;
	int cost;

public:
  Instrument(string name, string manufact, int year, int cost); 
	void PrintInfo();
};

#endif
