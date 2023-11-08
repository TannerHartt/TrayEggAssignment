#include "Cat.h"
#include <iostream>
#include <string>
using namespace std;

Cat::Cat(string name, int age, string breed) : Pet(name, age), catBreed(breed) {}

string Cat::GetBreed() {
	return catBreed;
}
