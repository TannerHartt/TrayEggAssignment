#include <iostream>
#include "Egg.h"
using namespace std;
#ifndef BIG_TIME_H // header guards
#define BIG_TIME_H // header guards

class Big_time {
    private: 
        Egg* eggs;
        int numEggs;
        int capacity;

    public: 
        Big_time();
        ~Big_time();
        void give_egg(Egg g);
        bool take_egg(Egg& g);
        void bubbleUp();
        void bubbleDown();
        void resize();
};

#endif