#include <iostream>
#include <fstream>
#include <sstream>
#include "factory_utils.h"
using namespace std;

char charSwap(char ch) {
        switch (ch) {
            case '|': 
                ch = '-';
                break;
            case '-': 
                ch = '|';
                break;
            case '/': 
                ch = '\\';
                break;
            case '\\':
                ch = '/';
                break;
        }
    return ch;
}

void load_conveyors(vector<Conveyor*> &assembly_line) {
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
    for(unsigned int i = 0; i < assembly_line.size(); i++)
        sout << *assembly_line.at(i) << "\n\n";
    
    return sout.str();
}

string vertical_report(const vector<Conveyor*> &assembly_line) {
    
    vector<string> strings;

    // Fill string vector with each conveyor to decide largest
    for (unsigned int i=0; i < assembly_line.size(); ++i) {
        ostringstream sout;
        sout << *assembly_line.at(i);
        strings.push_back(sout.str());
    }
    
    // Find largest conveyor size
    unsigned int largest = 0;
    for (string str : strings) {
        if (str.size() > largest) {
            largest = str.size();
        }
    }

    ostringstream sout;
    for (unsigned int i = 0; i < largest; i+=6) {
        for (unsigned int j = 0; j < strings.size(); j++) {
            for (unsigned int k = 0; k < 5; k++) {
                if ((i + k) < strings.at(j).size()) sout << strings.at(j).at(i + k);
                else sout << ' ';
            }
            sout << "  ";
        }
        sout << endl;
    }

    return sout.str();
}

string horizontal_report(const vector<Conveyor*> &assembly_line) {
    
    vector<string> strings;

    // Fill string vector with each conveyor
    for (unsigned int i=0; i < assembly_line.size(); ++i) {
        ostringstream sout;
        sout << *assembly_line.at(i);
        strings.push_back(sout.str());
    }

    unsigned int largest = 0;
    for (string str : strings) {
        if (str.size() > largest)
            largest = str.size();
    }

    ostringstream sout;
    for (unsigned int i = strings.size(); i--;) {
        for (unsigned col = 5; col > 0; col--) {
            for (unsigned row = 0; row < largest - 2; row+=6) {
                if (row + 6 < strings.at(i).size()) {
                    sout << charSwap(strings.at(i).at((row + col - 1)));
                } else {
                    sout << ' ';
                }
            }
            sout << endl;
        }

        for (unsigned int i = 0; i < largest/6; i++) {
            sout << " ";
        }
        sout << endl;
    }
    return sout.str();
}
