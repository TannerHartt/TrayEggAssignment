#ifndef CATH
#define CATH

#include <string>
#include "Pet.h"

class Cat : public Pet {
	public:
    Cat(string name, int age, string breed);
		void SetBreed(string userBreed);
		string GetBreed();

	private:
		string catBreed;
};

#endif
