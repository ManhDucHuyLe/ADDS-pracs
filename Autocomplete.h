#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  bool isEndOfWord;
};

class Autocomplete {
 private:
  TrieNode* root;
  void dfs(TrieNode* node, string word, vector<string>& suggestions);

 public:
  Autocomplete();

  void insert(string word);

  vector<string> getSuggestions(string partialWord);
};
