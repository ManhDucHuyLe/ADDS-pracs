#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <string>
#include <unordered_map>

using namespace std;

class PrefixMatcher {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode*> childNodes;
    int routerNumber;
  };

  TrieNode* root;

 public:
  PrefixMatcher();

  int selectRouter(string networkAddress);

  void insert(string address, int routerNumber);
};

#endif