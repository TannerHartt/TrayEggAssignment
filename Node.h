#ifndef NODE_H
#define NODE_H

#include<iostream>
using std::ostream;
class Payload_node;
struct Node {
  public: 
    Node(Node** wiat);
    virtual ~Node();
    virtual Node* admit(Payload_node* pledge)=0;
    virtual bool is_member(double value)=0;

  private: 
    Node** parental_hook;
    virtual ostream& output(ostream& os)=0;

    friend ostream& operator<<(ostream& os, Node& rhs);
    friend class Empty_node; //for easy access to parental_hook
    friend class Payload_node; //for easy access to parental_hook
};

#endif
