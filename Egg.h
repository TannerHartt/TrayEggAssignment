#include <iostream>
using namespace std;
#ifndef EGG_H // header guards
#define EGG_H // header guards

class Egg {
    private:
        float weightInOunces;
    
    public: 
        Egg();
        Egg(float weight);
        char getWeightChar();
        void clear();
        friend ostream& operator<<(ostream& os, const Egg& rhs);
        friend bool operator==(const Egg& lhs, const Egg& rhs);
        friend bool operator<(const Egg& lhs, const Egg& rhs);
};

#endif
