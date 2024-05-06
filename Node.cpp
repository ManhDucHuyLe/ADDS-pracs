
#include "Node.h"

Node::Node(int data, Node* link = nullptr) {
  this->data = data;
  this->link = link;
}