#include <iostream>
using namespace std;
#ifndef HARNESS_H // header guards
#define HARNESS_H // header guards
#include "Tray.h"

struct Harness {
    Tray* tray;
    Harness* next;
    Harness(Tray* t, Harness* n = nullptr);
    ~Harness();
    friend ostream& operator<<(ostream& os, const Harness& rhs);
};


#endif