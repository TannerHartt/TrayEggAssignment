#include <iostream>
using namespace std;
#ifndef CONVEYOR_H // header guards
#define CONVEYOR_H // header guards
#include "Tray.h"

class Conveyor {
    private: 
        struct Harness {
            Tray* currentTray;
            Harness* next;
            Harness(Tray* t, Harness* n = nullptr);
            ~Harness();
        };

        Harness* head;
        Harness* tail;
        int length;

    public:
        Conveyor();
        void attach_front(Tray* tray);
        void attach_back(Tray* caboose);
        friend ostream& operator<<(ostream& os, const Conveyor& rhs);
};

#endif