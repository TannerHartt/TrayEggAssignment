#include "StringInstrument.h"

StringInstrument::StringInstrument(string name, string manufact, int year, int cost, int strings, int frets, bool b) 
    : Instrument(name, manufact, year, cost), numStrings(strings), numFrets(frets), isBowed(b)
    {}

int StringInstrument::GetNumOfStrings() {
    return numStrings;
};

int StringInstrument::GetNumOfFrets() {
    return numFrets;
};

bool StringInstrument::GetIsBowed() {
    return isBowed;
};
