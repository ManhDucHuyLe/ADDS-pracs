#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
using namespace std;

class Document {
 public:
  int id;
  string name;
  int limit;
  Document(int id, string name, int limit);
};
#endif