#include "QuickSort.h"

int partition(std::vector<int>& list, int low, int high) {
  if (high - low + 1 >= 3) {
    int pivotIndex = low + 2;
    int pivot = list[pivotIndex];
    std::swap(list[pivotIndex], list[high]);

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
      if (list[j] < pivot) {
        i++;
        std::swap(list[i], list[j]);
      }
    }
    std::swap(list[i + 1], list[high]);
    return (i + 1);
  } else {
    int pivot = list[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
      if (list[j] < pivot) {
        i++;
        std::swap(list[i], list[j]);
      }
    }
    std::swap(list[i + 1], list[high]);
    return (i + 1);
  }
}

void quickSort(std::vector<int>& list, int low, int high) {
  if (low < high) {
    int _pivot = partition(list, low, high);

    quickSort(list, low, _pivot - 1);
    quickSort(list, _pivot + 1, high);
  }
}

std::vector<int> QuickSort::sort(std::vector<int> list) {
  quickSort(list, 0, list.size() - 1);
  return list;
}