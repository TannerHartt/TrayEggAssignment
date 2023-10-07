#include <iostream>
using namespace std;
#ifndef CONVEYOR_H // header guards
#define CONVEYOR_H // header guards
#include "Tray.h"

class Conveyor {
    private: 
        struct Harness {
            Tray *tray;
            Harness *next;
            Harness(Tray *t, Harness *n = nullptr);
            ~Harness();
            friend ostream &operator<<(ostream &os, const Harness &rhs) {
                os << " / \\ " << endl;
                os << "/   \\" << endl;
                os << *rhs.tray;
                os << "\\   /" << endl;
                os << " \\ / " << endl;
                if (!rhs.next) os << "  S  " << endl;
                else os << "  $  " << endl;
                return os;
            }
        };

        Harness* head;
        Harness* tail;
        int length;

    public:
        Conveyor();
        ~Conveyor();
        void attach_front(Tray* tray);
        void attach_back(Tray* caboose);
        friend ostream& operator<<(ostream& os, const Conveyor& rhs);
        void remove(const Tray& thisone);
};

#endif