#include <iostream>
using namespace std;
#include "Conveyor.h"
#include "Tray.h"

Conveyor::Conveyor() : head(nullptr), tail(nullptr), length(0) {}
Conveyor::Harness::Harness(Tray* t, Harness* n) : tray(t), next(n) {}
Conveyor::Harness::~Harness() { delete tray; }

Conveyor::~Conveyor() {
   Harness* curr = head;
   while (curr) {
      Harness* temp = curr;
      curr = curr->next;
      delete temp;
   }
}

void Conveyor::attach_front(Tray* engine) {
   if (!head) {
      Harness* curr = new Harness(engine);
      head = curr;
      tail = curr;
   } else {
      head = new Harness(engine, head);
   }
   length++;
}

void Conveyor::attach_back(Tray* caboose) {
   Harness* temp = new Harness(caboose);
   if (!head) {
      head = temp;
      tail = temp;      
   } else {
      tail->next = temp;
      tail = temp;
   }
   length++;
}

ostream& operator<<(ostream& os, const Conveyor& rhs) {
   os << "  |  " << endl;
   if (rhs.head == nullptr) {
      os << endl << endl;
      return os;
   }
   Conveyor::Harness* curr = rhs.head;
   while(curr) {
      os << *curr;
      curr = curr->next;
   }
   return os;
}

void Conveyor::remove(const Tray& searchTray) {
   
   Harness* prev = nullptr;
   Harness* curr = head;

    while (curr) {
        if (*curr->tray == searchTray) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            
            Harness* temp = curr;
            curr = curr->next;
            delete temp;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}


/*
Tray* detach_front();
   * return nullptr if there are 0 tray/harness in the conveyor
   * return the heads data (the tray)
   *  + before, reease the harness
   *  + before releasing the harness, assign nullptr to its data attribute
   * release harness after grabbing data
   * return nullptr if no more exist

*/
