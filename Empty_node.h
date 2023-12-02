#ifndef EMPTY_NODE_H
#define EMPTY_NODE_H
#include "Node.h"

class Empty_node : public Node{
  public:
    Empty_node(Node** parental_hook);
    virtual ostream& output(ostream& os);
    Node* admit(Payload_node* pledge);
    bool is_member(double value);
};

#endif
