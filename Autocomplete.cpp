#include "Autocomplete.h"

#include <iostream>

void Autocomplete::search(TrieNode* node, string word,
                          vector<string>& suggestions) {
  if (node->isEndOfWord) {
    suggestions.push_back(word);
  }
  for (auto& pair : node->childNodes) {
    search(pair.second, word + pair.first, suggestions);
  }
}

Autocomplete::Autocomplete() {
  root = new TrieNode();
  root->isEndOfWord = false;
}

void Autocomplete::insert(string word) {
  TrieNode* current = root;
  for (char c : word) {
    if (current->childNodes.find(c) == current->childNodes.end()) {
      current->childNodes[c] = new TrieNode();
    }
    current = current->childNodes[c];
  }
  current->isEndOfWord = true;
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
  vector<string> suggestions;
  TrieNode* current = root;
  for (char c : partialWord) {
    if (current->childNodes.find(c) == current->childNodes.end()) {
      return suggestions;
    }
    current = current->childNodes[c];
  }
  search(current, partialWord, suggestions);
  return suggestions;
}
