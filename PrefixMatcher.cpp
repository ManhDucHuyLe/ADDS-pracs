#include "PrefixMatcher.h"

#include <iostream>

PrefixMatcher::PrefixMatcher() {
  root = new TrieNode();
  root->routerNumber = -1;
}

int PrefixMatcher::selectRouter(string networkAddress) {
  TrieNode* current = root;
  int selectedRouter = -1;
  for (char c : networkAddress) {
    if (current->childNodes.find(c) == current->childNodes.end()) {
      break;
    }
    current = current->childNodes[c];
    if (current->routerNumber != -1) {
      selectedRouter = current->routerNumber;
    }
  }
  return selectedRouter;
}

void PrefixMatcher::insert(string address, int routerNumber) {
  TrieNode* current = root;
  for (char c : address) {
    if (current->childNodes.find(c) == current->childNodes.end()) {
      current->childNodes[c] = new TrieNode();
    }
    current = current->childNodes[c];
  }
  current->routerNumber = routerNumber;
}