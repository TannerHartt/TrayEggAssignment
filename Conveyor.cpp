#include <iostream>
using namespace std;
#include "Conveyor.h"
#include "Tray.h"

Conveyor::Conveyor() : head(nullptr), tail(nullptr), length(0) {}

Conveyor::Harness::Harness(Tray* t, Harness* n) : currentTray(t), next(n) {}

void Conveyor::attach_front(Tray* engine) {
   Harness* curr = new Harness(engine);
   if (length == 0) {
      head = curr;
      tail = curr;
   }
   else {
      curr->next = head;
      head = curr;
   }
   length++;
}

void Conveyor::attach_back(Tray* caboose) {
   Harness* temp = new Harness(caboose);
   if (length == 0) {
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
   while (rhs.head) {
      
   }
   
   return os;
}