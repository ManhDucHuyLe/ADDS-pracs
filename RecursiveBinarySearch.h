#include <vector>

class RecursiveBinarySearch {
 private:
  bool binarySearch(std::vector<int>& list, int start, int end, int item);

 public:
  bool search(std::vector<int>& list, int item);
};