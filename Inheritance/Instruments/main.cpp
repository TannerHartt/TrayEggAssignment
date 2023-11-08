#include "StringInstrument.h"

int main() {

		string instrumentName, manufacturerName, stringInstrumentName, stringManufacturer;
		int yearBuilt, cost, stringYearBuilt, stringCost, numStrings, numFrets;
		bool bowed;

		cin >> instrumentName;
		cin >> manufacturerName;
		cin >> yearBuilt;
		cin >> cost;

		cin >> stringInstrumentName;
		cin >> stringManufacturer;
		cin >> stringYearBuilt;
		cin >> stringCost;
		cin >> numStrings;
		cin >> numFrets;
		cin >> bowed;

		Instrument myInstrument(instrumentName, manufacturerName, yearBuilt, cost);
		myInstrument.PrintInfo();

		StringInstrument myStringInstrument(
        stringInstrumentName, 
        stringManufacturer,
        stringYearBuilt,
        stringCost,
        numStrings,
        numFrets,
        bowed);

		myStringInstrument.PrintInfo();

		cout << "   Number of strings: " << myStringInstrument.GetNumOfStrings() << endl;
		cout << "   Number of frets: " << myStringInstrument.GetNumOfFrets() << endl;
		cout << "   Is bowed: " << std::boolalpha << myStringInstrument.GetIsBowed() << endl;
}
