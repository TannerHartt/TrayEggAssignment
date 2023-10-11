#include <iostream>
#include <fstream>
#include <sstream>
#include "factory_utils.h"
using namespace std;

void load_conveyors(vector<Conveyor*> &assembly_line)
{
    string input;
    Conveyor *convey;
    Tray *currTray;

    while (getline(cin, input)) {
        if (input[0] == 'T') {
            currTray = new Tray();
            convey->attach_back(currTray);
        }
        else if (input[0] == 'C') {
            convey = new Conveyor();
            assembly_line.push_back(convey);
        }
        else {
            float egg = stof(input);
            currTray->place_back(Egg(egg));
        }
    }
}

string basic_report(const vector<Conveyor*> &assembly_line) {
    ostringstream sout;
    for(unsigned int i = 0; i < assembly_line.size(); i++) {
        sout << *assembly_line.at(i) << "\n\n";
    }
    return sout.str();
}

string vertical_report(const vector<Conveyor*> &assembly_line) {
    ostringstream sout;
    string report = basic_report(assembly_line);
    vector<string> strings;

    for (Conveyor* convey : assembly_line) {
        strings.push_back(report);
        
    }

    
    int largest = 0;
    for (int i = 0; i < strings.size(); i++) {
        string temp = strings[i];
        if (temp.size() > largest) {
            largest = temp.size();
        }
    }


    return sout.str();
}
