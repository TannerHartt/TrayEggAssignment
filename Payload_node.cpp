#include "Payload_node.h"
#include "Empty_node.h"

ostream& Payload_node::output(ostream& os)
{
  os << '(';
  left->output(os);
  os << '<' << payload << '>';
  right->output(os);
  os << ')';
  return os;
};

Payload_node::Payload_node(double pl) : Node(nullptr), payload(pl), left(new Empty_node(&left)), right(new Empty_node(&right)) {};

Payload_node::~Payload_node() {
  delete left;
  delete right;
};

Node* Payload_node::admit(Payload_node* pledge) {
  if (pledge->payload < payload) return left->admit(pledge);
  else return right->admit(pledge);  
};

bool Payload_node::is_member(double value) {
  if (value == payload) return true;
  else if (value < payload) return left->is_member(value);
  else return right->is_member(value);
};