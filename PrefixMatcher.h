#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  int routerNumber;
};

class PrefixMatcher {
 private:
  TrieNode* root;

 public:
  PrefixMatcher();

  void insert(string address, int routerNumber);

  int selectRouter(string networkAddress);
};
