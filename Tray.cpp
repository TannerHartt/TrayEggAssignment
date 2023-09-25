#include <iostream>
using namespace std;
#include "Egg.h"
#include "Tray.h"

 // Initialization list with desired initial values.
Tray::Tray() : carton(new Egg[2]), capacity(2), currentEggs(0) {}
Tray::~Tray() {
    delete[] carton; // Release the memory allocated at the address.
}

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
}   

ostream& operator<<(ostream& os, const Tray& rhs) {
    os << "+---+\n";
    
    for (int i = 0; i < rhs.capacity; i+=2) {
        if (i != 0) os << "|-+-|\n";
        os << "|" << rhs.carton[i] << "|" << rhs.carton[i+1] << "|\n";
    }
    
    os << "+---+\n";
    return os;
}


// This is another solution, using a while loop. (More complicated than the one above.)
// ostream& operator<<(ostream& os, const Tray& rhs) {
//     os << "+---+\n";
    
//     int index = 0;
//     while (index < rhs.capacity) {
//         os << "|"; // Print the left side of the carton.

//         // Print the eggs in the carton. 
//         for (int i = 0; i < 2; i++) {
//             int egg = index + i; // Calculate the index of the egg in the carton.

//             if (egg < rhs.currentEggs) os << rhs.carton[egg]; // Print the egg if it exists.
//             else os << " "; // Print a space if there is no egg at the index.
            
//             if (i == 0) os << "|"; // Print the divider between the eggs.
//         }

//         os << "|\n"; // Print the right side of the carton.
//         index += 2; // Increment the index by 2 to move to the next row.

//         if (rhs.capacity > index) { 
//             os << "|-+-|\n"; // Print the divider between the rows.
//         }
//     }

//     os << "+---+\n";
//     return os;
// }

// This function should compare the eggs in each carton and return true if they have the same amount of each egg in each carton.
// The trays are conidered equal if they have the same number of eggs and the same number of each egg.
bool operator==(const Tray& lhs, const Tray& rhs) {
    
    if (lhs.currentEggs != rhs.currentEggs || lhs.capacity != rhs.capacity)
        return false;
    else if (lhs.currentEggs == 0 && rhs.currentEggs == 0)
        return true;
    
    int lhsEggs[7] = {0};
    int rhsEggs[7] = {0};

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
            lhsEggs[0]++;
        } else if (lhs.carton[i].getWeightChar() == '.') {
            lhsEggs[1]++;
        } else if (lhs.carton[i].getWeightChar() == '*') {
            lhsEggs[2]++;
        } else if (lhs.carton[i].getWeightChar() == 'o') {
            lhsEggs[3]++;
        } else if (lhs.carton[i].getWeightChar() == 'O') {
            lhsEggs[4]++;
        } else if (lhs.carton[i].getWeightChar() == '0') {
            lhsEggs[5]++;
        } else if (lhs.carton[i].getWeightChar() == '@') {
            lhsEggs[6]++;
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
}


void Tray::remove(Egg badEgg) { // This function is suppose to remove all eggs of the same weight class in the tray.
    

    for (int i = 0; i < currentEggs; i++) {
        if (carton[i] == badEgg) {
            for (int j = i; j < currentEggs; j++) 
                carton[j] = carton[j+1];
            
            currentEggs--;
            i--;
        }
    }
}

void Tray::place_front(Egg egg) { 

    if (currentEggs != capacity) { 
        for (int i = currentEggs; i >= 0; i--) 
            carton[i+1] = carton[i]; 
    } else {
        Egg* newCarton = new Egg[capacity + 2];
        for (int i = 0; i < currentEggs; i++) 
            newCarton[i+1] = carton[i];

        delete[] carton;
        carton = newCarton;
        capacity += 2;
    } 
    carton[0] = egg;
    currentEggs++;
}