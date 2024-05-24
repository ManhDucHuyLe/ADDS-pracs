#include <string>
#include <unordered_map>
#include <vector>

#include "Document.h"
#include "Patron.h"

using namespace std;

#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

class DocumentManager {
 private:
  unordered_map<int, Document*> doc_id_obj_map;
  unordered_map<int, Patron*> patron_id_obj_map;
  unordered_map<int, vector<int>> borrower_map;

 public:
  void addDocument(string name, int d, int limit);

  void addPatron(int p);

  int search(string dn);

  bool borrowDocument(int d, int p);

  void returnDocument(int d, int p);
};
#endif