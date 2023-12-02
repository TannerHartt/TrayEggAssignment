#include "SmartBST.h"
#include "Node.h"
#include "Empty_node.h"
#include "Payload_node.h"
#include<iostream>
using std::ostream;

ostream& operator<<(ostream& os, SmartBST& rhs)
{ return os << *rhs.root; };

SmartBST::SmartBST() : root(new Empty_node(&root)) {};

SmartBST::~SmartBST() { delete root; };

void SmartBST::insert(double payload) {
    Payload_node* node = new Payload_node(payload);
    delete root->admit(node);
};

bool SmartBST::exists(double value) {
    return root->is_member(value);
};
