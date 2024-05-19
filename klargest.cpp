#include <iostream>
#include <queue>
#include <vector>

int kth_largest(std::vector<int> values, int k) {
  std::priority_queue<int> list;

  for (int val : values) {
    list.push(val);
  }

  for (int i = 0; i < k - 1; i++) {
    list.pop();
  }

  return list.top();
}
