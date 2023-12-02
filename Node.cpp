#include "Node.h"

ostream& operator<<(ostream& os, Node& rhs)
{
  return rhs.output(os);
}

Node::~Node(){}

Node::Node(Node** wiat) : parental_hook(wiat) {};