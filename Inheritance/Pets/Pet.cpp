#include "Pet.h"
#include <iostream>
#include <string>
using namespace std;

Pet::Pet(string name, int age) : petName(name), petAge(age) {}

string Pet::GetName() {
	return petName;
}

int Pet::GetAge() {
	return petAge;
}

void Pet::PrintInfo() {
	cout << "Pet Information: " << endl;
	cout << "   Name: " << petName << endl;
	cout << "   Age: " << petAge << endl;
}
