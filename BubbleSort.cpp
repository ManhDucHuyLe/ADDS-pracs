#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
  int i, j;
  bool swapped;
  for (i = 0; i < list.size() - 1; i++) {
    swapped = false;
    for (j = 0; j < list.size() - i - 1; j++) {
      if (list[j] > list[j + 1]) {
        std::swap(list[j], list[j + 1]);
        swapped = true;
      }
    }

    if (swapped == false) break;
  }
  return list;
};
