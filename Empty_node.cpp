#include "Empty_node.h"
#include "Payload_node.h"

ostream& Empty_node::output(ostream& os)
{ return os << '_'; };

Empty_node::Empty_node(Node** ph) : Node(ph) {};

Node* Empty_node::admit(Payload_node* pledge) {
     *parental_hook=pledge; //parent now points to pledge
      pledge->parental_hook=parental_hook; //pledge now points to parent
      return this; //the empty node returns itself to the caller to be released.
};

bool Empty_node::is_member(double value) {
      return false;
};