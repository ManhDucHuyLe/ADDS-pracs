#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Autocomplete {
 private:
  struct TrieNode {
    unordered_map<char, TrieNode*> childNodes;
    bool isEndOfWord;
  };

  TrieNode* root;
  void search(TrieNode* node, string word, vector<string>& suggestions);

 public:
  Autocomplete();

  void insert(string word);

  vector<string> getSuggestions(string partialWord);
};

#endif
