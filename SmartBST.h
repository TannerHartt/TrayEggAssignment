#ifndef SMARTBST_H
#define SMARTBST_H
#include "Node.h"

class SmartBST {
  public:
    SmartBST();
    ~SmartBST();
    void insert(double payload);
    bool exists(double value);
  private:
    Node* root;

    friend ostream& operator<<(ostream& os, SmartBST& rhs);
};
#endif
