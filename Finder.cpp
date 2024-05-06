#include "Finder.h"

#include <unordered_map>

using namespace std;

vector<int> Finder::findSubstrings(string s1, string s2) {
  vector<int> result;
  int n = s1.size(), m = s2.size();
  for (int i = 0; i < m; ++i) {
    int hash_s2 = s2[i];

    int hash_s1 = s1[0];

    for (int j = 0; j <= n - 1; ++j) {
      if (hash_s1 == hash_s2) {
        if (s1.substr(j, m) == s2) {
          result.push_back(j);
          break;
        } else {
          result.push_back(-1);
          break;
        }
      }

      if (j < n - 1) {
        hash_s1 = s1[j + 1];
      }
    }
  }

  if (result.empty()) {
    for (int i = 0; i < m; ++i) {
      result.push_back(-1);
    }
  }

  return result;
}
