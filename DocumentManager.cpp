#include "DocumentManager.h"

#include <algorithm>

void DocumentManager::addDocument(string name, int d, int limit) {
  if (doc_id_obj_map.find(d) == doc_id_obj_map.end()) {
    doc_id_obj_map.insert(make_pair(d, new Document(d, name, limit)));
    vector<int> borrowerList;
    borrower_map.insert(make_pair(d, borrowerList));
  }
}

void DocumentManager::addPatron(int p) {
  if (patron_id_obj_map.find(p) == patron_id_obj_map.end()) {
    patron_id_obj_map.insert(make_pair(p, new Patron(p)));
  }
}

int DocumentManager::search(string dn) {
  auto it = doc_id_obj_map.begin();
  while (it != doc_id_obj_map.end() && it->second->name != dn) {
    it++;
  }
  if (it != doc_id_obj_map.end()) {
    return it->second->id;
  }
  return 0;
}

bool DocumentManager::borrowDocument(int d, int p) {
  auto d_ref = doc_id_obj_map.find(d);
  auto p_ref = patron_id_obj_map.find(p);
  auto b_ref = borrower_map.find(d);
  if ((d_ref == doc_id_obj_map.end()) || (p_ref == patron_id_obj_map.end()) ||
      (d_ref->second->limit <= (int)b_ref->second.size())) {
    return false;
  } else {
    b_ref->second.push_back(p);
    return true;
  }
}

void DocumentManager::returnDocument(int d, int p) {
  auto d_ref = doc_id_obj_map.find(d);
  auto p_ref = patron_id_obj_map.find(p);
  auto b_ref = borrower_map.find(d);
  if ((d_ref != doc_id_obj_map.end()) && (p_ref != patron_id_obj_map.end()) &&
      (b_ref != borrower_map.end())) {
    auto borrower_it = std::find(b_ref->second.begin(), b_ref->second.end(), p);
    if (borrower_it != b_ref->second.end()) {
      b_ref->second.erase(borrower_it);
    }
  }
}
