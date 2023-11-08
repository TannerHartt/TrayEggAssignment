#include <iostream>
#include<string>
#include "Cat.h"
#include "Pet.h"

using namespace std;

int main() {

	string petName, catName, catBreed;
	int petAge, catAge;

	getline(cin, petName);
	cin >> petAge;
	cin.ignore();
	getline(cin, catName);
	cin >> catAge;
	cin.ignore();
	getline(cin, catBreed);

	// TODO: Create a Pet object (using petName, petage) and then call PrintInfo
	Pet pet = Pet(petName, petAge);
	pet.PrintInfo();


	// TODO: Create a Cat object (using catName, catAge, catBreed) and then call PrintInfo
	Cat cat = Cat(catName, catAge, catBreed);
	cat.PrintInfo();


	// TODO: Use GetBreed(), to output the breed of the cat
	cout << "   Breed: " << cat.GetBreed() << endl;


}
