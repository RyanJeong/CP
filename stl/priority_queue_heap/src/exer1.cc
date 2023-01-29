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

int main() {
  CP;

  int n;
  std::cin >> n;
  std::priority_queue<int> max_heap;

  while (n--) {
    int x;
    std::cin >> x;

    if (!x) {
      if (max_heap.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << max_heap.top() << '\n';
        max_heap.pop();
      }
    } else {
      max_heap.push(x);
    }
  }

  return 0;
}
