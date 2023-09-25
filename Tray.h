#ifndef TRAY_H // header guards
#define TRAY_H // header guards
#include <iostream>
using namespace std;
#include "Egg.h"


class Tray {
    private:
        Egg* carton;
        int capacity;
        int currentEggs;



    public:
        Tray();
        ~Tray();
        void place_back(Egg egg);
        void place_front(Egg egg);
        void remove(Egg badEgg);
        friend ostream& operator<<(ostream& os, const Tray& rhs);
        friend bool operator==(const Tray& lhs, const Tray& rhs);
};

ostream& operator<<(ostream& os, const Tray& rhs);

#endif
