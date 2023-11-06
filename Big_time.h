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

// Big time sorter main function
// Lab 2
/*
int main() {
    vector<Conveyor*> v;
    for (int i=0; i< assemblyLine.size(); i++) {
        Conveyor* curr = assembpyLine.at(i)
        Conveoyr* sorted = new Conveyor;
        Tray* tp;
        while ((tp=curr->detach_front()) != nullptr) {
            Egg g;
            Big_time bt;
            while(tp->take_back(g) == true) {
                bt.give_egg(g);
            }
            while(bt.take_egg(g) == true) {
                tp->place_back(g);
            }
            sorted->attach_back(tp);
        }

        delete curr;
        v.push_back(sorted);
    }
    vertical_report(v);
}
*/