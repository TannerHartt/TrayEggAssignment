#include "Instrument.h"

Instrument::Instrument(string name, string manufact, int year, int cost)
  :instrumentName(name), instrumentManufacturer(manufact), yearBuilt(year), cost(cost)
{}

void Instrument::PrintInfo() {
	cout << "Instrument Information: " << endl;
	cout << "   Name: " << instrumentName << endl;
	cout << "   Manufacturer: " << instrumentManufacturer << endl;
	cout << "   Year built: " << yearBuilt << endl;
	cout << "   Cost: " << cost << endl;
}
