#include <iostream>
#include "Conveyor.h"
#include "factory_utils.h"
#include "Big_time.h"
#include "Tray.h"
#include <vector>
using namespace std;


int main() {
    vector<Conveyor*> assembly_line;
    load_conveyors(assembly_line);
    vector<Conveyor*> ordered_line;
    Big_time bt;

    for (Conveyor* curr : assembly_line) {
        Conveyor* sorted = new Conveyor();
        Tray* tp = curr->detach_front();
        while (tp != nullptr) {
            Egg g;
            while (tp->take_back(g))
                bt.give_egg(g);

            while (bt.take_egg(g))
                tp->place_back(g);

            sorted->attach_back(tp);
            tp = curr->detach_front();
        }

        delete curr;
        ordered_line.push_back(sorted);
    }

    cout << "Ordered vertical report:\n" <<  vertical_report(ordered_line);
    for (Conveyor* conveyor : ordered_line) {
        delete conveyor;
    }
        
   return 0;
};