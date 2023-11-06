#include <iostream>
using namespace std;
#include "Egg.h" 


Egg::Egg() : weightInOunces(0) { };

Egg::Egg(float weight) : weightInOunces(weight) { };

ostream& operator<<(ostream& os, const Egg& rhs)
{
  if (rhs.weightInOunces == 0) {
    os << " ";
  } else if (rhs.weightInOunces < 1.25) {
    os << "E";
  } else if (rhs.weightInOunces < 1.50) {
    os << ".";
  } else if (rhs.weightInOunces < 1.75) {
    os << "*";
  } else if (rhs.weightInOunces < 2.00) {
    os << "o";
  } else if (rhs.weightInOunces < 2.25) {
    os << "O";
  } else if (rhs.weightInOunces < 2.50) {
    os << "0";
  } else if (rhs.weightInOunces >= 2.5) {
    os << "@";
  }
  return os;
};

// bool operator==(const Egg& lhs, const Egg& rhs) {
//     if (lhs.weightInOunces < 1.25 && rhs.weightInOunces < 1.25) {
//       return true;
//     } else if (lhs.weightInOunces >= 1.25 && lhs.weightInOunces < 1.5 &&
//         rhs.weightInOunces >= 1.25 && rhs.weightInOunces < 1.5 ) {
//         return true;
//     } else if (lhs.weightInOunces >= 1.5 && lhs.weightInOunces < 1.75 &&
//                rhs.weightInOunces >= 1.5 && rhs.weightInOunces < 1.75 ) {
//                return true;
//     } else if (lhs.weightInOunces >= 1.75 && lhs.weightInOunces < 2.0 && 
//                 rhs.weightInOunces >= 1.75 && rhs.weightInOunces < 2.0 ) {
//                 return true;
//     } else if (lhs.weightInOunces >= 2.0 && lhs.weightInOunces < 2.25 && 
//                 rhs.weightInOunces >= 2.0 && rhs.weightInOunces < 2.25 ) {
//                 return true;
//     } else if (lhs.weightInOunces >= 2.25 && lhs.weightInOunces < 2.5 && 
//                 rhs.weightInOunces >= 2.25 && rhs.weightInOunces < 2.5 ) {
//                 return true;
//     } else if (lhs.weightInOunces >= 2.5 && rhs.weightInOunces >= 2.5) {
//         return true;
//     }
//     return false;
// };

bool operator==(const Egg& lhs, const Egg& rhs) {
    return lhs.weightInOunces == rhs.weightInOunces;
}

char Egg::getWeightChar() {
    if (weightInOunces < 1.25) return 'E'; 
    else if (weightInOunces >= 1.25 && weightInOunces < 1.5) return '.';
    else if (weightInOunces >= 1.5 && weightInOunces < 1.75) return '*';
    else if (weightInOunces >= 1.75 && weightInOunces < 2.0) return 'o';
    else if (weightInOunces >= 2.0 && weightInOunces < 2.25) return 'O';
    else if (weightInOunces >= 2.25 && weightInOunces < 2.5) return '0';
    else if (weightInOunces >= 2.5) return '@';
    return ' '; // Should never get here.
};

bool operator<(const Egg& lhs, const Egg& rhs) {
  return lhs.weightInOunces < rhs.weightInOunces;
}

bool operator<=(const Egg& lhs, const Egg& rhs) {
    return lhs < rhs || lhs == rhs;
}
 void Egg::clear() {
    weightInOunces = 0;
 }