#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"
using namespace std;

class StringInstrument : public Instrument {

  	public: 
		StringInstrument(string name, string manufact, int year, int cost, int strings, int frets, bool isBowed);
		int GetNumOfStrings();
		int GetNumOfFrets();
		bool GetIsBowed();
		
	private: 
		int numStrings;
		int numFrets;
		bool isBowed;
};

#endif
