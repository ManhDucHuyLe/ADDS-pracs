#include <iostream>
#include <vector>

#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
  std::vector<int> list;
  int num;
  while (std::cin >> num) {
    list.push_back(num);
  }

  QuickSort quickSort;

  std::vector<int> sortedList = quickSort.sort(list);

  RecursiveBinarySearch assit;

  bool found = assit.search(sortedList, 1);

  if (found) {
    std::cout << "true"
              << " ";
  } else {
    std::cout << "false"
              << " ";
  }

  for (int m : sortedList) {
    std::cout << m << " ";
  }
  std::cout << std::endl;

  return 0;
}