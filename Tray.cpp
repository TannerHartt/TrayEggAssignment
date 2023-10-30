#include <iostream>
using namespace std;
#include "Egg.h"
#include "Tray.h"

 // Initialization list with desired initial values.
Tray::Tray() : carton(new Egg[2]), capacity(2), currentEggs(0) {}

Tray::~Tray() {
    delete[] carton; // Release the memory allocated at the address.
};

void Tray::place_back(Egg egg) {
    if (currentEggs == capacity) {

        Egg* newCarton = new Egg[capacity + 2];
        for (int i = 0; i < capacity; i++) 
            newCarton[i] = carton[i];
        
        delete[] carton;
        carton = newCarton;
        capacity += 2;
    }
    carton[currentEggs] = egg;
    currentEggs++;
};

ostream& operator<<(ostream& os, const Tray& rhs) {
    os << "+---+\n";
    
    for (int i = 0; i < rhs.capacity; i+=2) {
        if (i != 0) os << "|-+-|\n";
        os << "|" << rhs.carton[i] << "|" << rhs.carton[i+1] << "|\n";
    }
    
    os << "+---+\n";
    return os;
};


// The trays are conidered equal if they have the same number of eggs and the same number of each egg.
bool operator==(const Tray& lhs, const Tray& rhs) {
    
    // Base case checks
    if (lhs.currentEggs != rhs.currentEggs || lhs.capacity != rhs.capacity)
        return false;
    if (lhs.currentEggs == 0 && rhs.currentEggs == 0)
        return true;
    
    int lhsEggs[7] = {0}; // Shorthand to set all elements with a default value of 0
    int rhsEggs[7] = {0}; // Can also be written as 'int rhsEggs[7]{0}'

    /*
    Array index layout
    0 - Error
    1 - Peewee
    2 - Small
    3 - Medium
    4 - Large
    5 - X-Large
    6 - Jumbo
    */

    // Count the number of each egg type in the left hand side carton.
    for (int i = 0; i < lhs.currentEggs; i++) {
        if (lhs.carton[i].getWeightChar() == 'E') {
            lhsEggs[0]++; // Increment error count
        } else if (lhs.carton[i].getWeightChar() == '.') {
            lhsEggs[1]++; // Increment peewee count
        } else if (lhs.carton[i].getWeightChar() == '*') {
            lhsEggs[2]++; // Increment small count
        } else if (lhs.carton[i].getWeightChar() == 'o') {
            lhsEggs[3]++; // Increment medium count
        } else if (lhs.carton[i].getWeightChar() == 'O') {
            lhsEggs[4]++; // Increment large count
        } else if (lhs.carton[i].getWeightChar() == '0') {
            lhsEggs[5]++; // Increment xlarge count
        } else if (lhs.carton[i].getWeightChar() == '@') {
            lhsEggs[6]++; // Increment jumbo count
        }
    }

    // Count the number of each egg type in the right hand side carton.
    for (int i = 0; i < rhs.currentEggs; i++) {
        if (rhs.carton[i].getWeightChar() == 'E') {
            rhsEggs[0]++;
        } else if (rhs.carton[i].getWeightChar() == '.') {
            rhsEggs[1]++;
        } else if (rhs.carton[i].getWeightChar() == '*') {
            rhsEggs[2]++;
        } else if (rhs.carton[i].getWeightChar() == 'o') {
            rhsEggs[3]++;
        } else if (rhs.carton[i].getWeightChar() == 'O') {
            rhsEggs[4]++;
        } else if (rhs.carton[i].getWeightChar() == '0') {
            rhsEggs[5]++;
        } else if (rhs.carton[i].getWeightChar() == '@') {
            rhsEggs[6]++;
        }
    }

    // Compare the number of each egg type in each carton.
    for (int i = 0; i < 7; i++) {
        if (lhsEggs[i] != rhsEggs[i]) // If the number of eggs of a certain type is not equal, return false.
            return false;
    }
    return true; // If this is reached, then the number of eggs of each type is equal - therefor the trays are equal.
};

void Tray::remove(Egg badEgg) {
    for (int i = 0; i < currentEggs; i++) {
        if (carton[i] == badEgg) {
            for (int j = i; j < currentEggs; j++)
                carton[j] = carton[j+1];
            
            currentEggs--;
            i--;
        }
    }
};

void Tray::place_front(Egg egg) { 

    if (currentEggs != capacity) { 
        for (int i = currentEggs; i >= 0; i--) 
            carton[i+1] = carton[i]; // If carton is not full, shift all existing elements to the right one position
    } else { // If carton is full, then create a new one with 2 more slots and copy all elements
        Egg* newCarton = new Egg[capacity + 2];
        for (int i = 0; i < currentEggs; i++)
            newCarton[i+1] = carton[i]; // Copy all elements over and shift them to the right one place.

        delete[] carton; // Delete old carton memory
        carton = newCarton; // Update carton to the new carton
        capacity += 2; // Increase capacity variable to reflect new size.
    } 
    carton[0] = egg;
    currentEggs++;
};

bool Tray::take_back(Egg& e) {
    if (currentEggs == 0) return false;
    e = carton[currentEggs - 1];
    carton[currentEggs - 1].clear();
    currentEggs--;
    return true;
}
