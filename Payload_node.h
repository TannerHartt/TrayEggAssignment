#ifndef PAYLOAD_NODE_H
#define PAYLOAD_NODE_H
#include "Node.h"

class Payload_node : public Node {
  public:
    Payload_node(double p_load);
    virtual ~Payload_node();
    Node* admit(Payload_node* pledge);
    bool is_member(double value);
  private:
    virtual ostream& output(ostream& os);
    double payload;
    Node* left;
    Node* right;
};

#endif
