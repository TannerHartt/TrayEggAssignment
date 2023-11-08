#ifndef PETH
#define PETH

#include <string>
using namespace std;

class Pet {

	public:
    	Pet(string name, int age);
		string GetName();
		int GetAge();
		void PrintInfo();

	protected:
		string petName;
		int petAge;
};

#endif
