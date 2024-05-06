#include "Autocomplete.h"

void Autocomplete::dfs(TrieNode* node, string word,
                       vector<string>& suggestions) {
  if (node->isEndOfWord) {
    suggestions.push_back(word);
  }
  for (auto& pair : node->children) {
    dfs(pair.second, word + pair.first, suggestions);
  }
}

Autocomplete::Autocomplete() {
  root = new TrieNode();
  root->isEndOfWord = false;
}

void Autocomplete::insert(string word) {
  TrieNode* current = root;
  for (char c : word) {
    if (current->children.find(c) == current->children.end()) {
      current->children[c] = new TrieNode();
    }
    current = current->children[c];
  }
  current->isEndOfWord = true;
}

vector<string> Autocomplete::getSuggestions(string partialWord) {
  vector<string> suggestions;
  TrieNode* current = root;
  for (char c : partialWord) {
    if (current->children.find(c) == current->children.end()) {
      return suggestions;  // Return empty vector if no words start with
                           // partialWord
    }
    current = current->children[c];
  }
  dfs(current, partialWord, suggestions);
  return suggestions;
}

int main() {
  Autocomplete autocomplete;
  autocomplete.insert("bin");
  autocomplete.insert("ball");

  vector<string> suggestions = autocomplete.getSuggestions("b");
  // suggestions now contains: "bin", "ball", "ballet"

  suggestions = autocomplete.getSuggestions("ba");
  // suggestions now contains: "ball", "ballet"

  // Print the suggestions
  for (const string& word : suggestions) {
    cout << word << endl;
  }
  return 0;
}
