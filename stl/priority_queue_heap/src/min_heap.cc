/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  while (n--) {
    int x;
    std::cin >> x;
    if (x) {
      min_heap.push(x);
    } else {
      if (min_heap.empty()) {
        std::cout << '0';
      } else {
        std::cout << min_heap.top();
        min_heap.pop();
      }
      std::cout << '\n';
    }
  }

  return 0;
}
