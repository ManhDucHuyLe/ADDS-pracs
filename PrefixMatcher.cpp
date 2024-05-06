#include "PrefixMatcher.h"

#include <iostream>

PrefixMatcher::PrefixMatcher() {
  root = new TrieNode();
  root->routerNumber = -1;
}

void PrefixMatcher::insert(string address, int routerNumber) {
  TrieNode* current = root;
  for (char c : address) {
    if (current->children.find(c) == current->children.end()) {
      current->children[c] = new TrieNode();
    }
    current = current->children[c];
  }
  current->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress) {
  TrieNode* current = root;
  int selectedRouter = -1;
  for (char c : networkAddress) {
    if (current->children.find(c) == current->children.end()) {
      break;
    }
    current = current->children[c];
    if (current->routerNumber != -1) {
      selectedRouter = current->routerNumber;
    }
  }
  return selectedRouter;
}

int main() {
  // Create a PrefixMatcher object
  PrefixMatcher prefixMatcher;

  // Insert router addresses into the PrefixMatcher object
  prefixMatcher.insert("1100110111", 1);
  prefixMatcher.insert("110011011", 2);
  prefixMatcher.insert("11001101", 3);

  // Select a router for a network address
  int routerNumber = prefixMatcher.selectRouter("110011011001");

  // Print the router number
  cout << "Selected Router: " << routerNumber << endl;

  return 0;
}