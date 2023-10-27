#include <iostream>
#include <vector>
#include "Conveyor.h"
using namespace std;
#ifndef FACTORY_UTILS_H // header guards
#define FACTORY_UTILS_H // header guards

void load_conveyors(vector<Conveyor *> &assembly_line);
string basic_report(const vector<Conveyor*>& assembly_line);
string vertical_report(const vector<Conveyor*>& assembly_line);
string horizontal_report(const vector<Conveyor*>& assembly_line);

#endif