#include "Document.h"

Document::Document(int id, string name, int limit) {
  this->id = id;
  this->name = name;
  this->limit = limit;
}

Document::Document() {
  this->id = 0;
  this->name = "";
  this->limit = 0;
}
