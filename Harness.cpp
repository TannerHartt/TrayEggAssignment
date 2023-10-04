#include <iostream>
using namespace std;
#include "Harness.h"
#include "Tray.h"


Harness::~Harness() {
    delete tray;
};

Harness::Harness(Tray* t, Harness* n) : tray(t), next(n) {};


ostream& operator<<(ostream& os, const Harness& rhs) {
    os << " / \\ " << endl;
    os << "/   \\" << endl;
    os << *rhs.tray;
    os << "\\   /" << endl;
    os << " \\ / " << endl;
    if (!rhs.next) os << "  S  " << endl;
    else os << "  $  " << endl;
    return os;
}