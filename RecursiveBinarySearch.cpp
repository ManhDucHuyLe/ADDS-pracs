#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int>& list, int item) {
  return binarySearch(list, 0, list.size() - 1, item);
}

bool RecursiveBinarySearch::binarySearch(std::vector<int>& list, int start,
                                         int end, int item) {
  if (start <= end) {
    int mid = start + (end - start) / 2;

    if (list[mid] == item) {
      return true;
    }

    if (list[mid] > item) {
      return binarySearch(list, start, mid - 1, item);
    }
    return binarySearch(list, mid + 1, end, item);
  }
  return false;
}