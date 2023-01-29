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
  while (n--) {
    int m;
    std::cin >> m;
    std::cout << m / 2 + 1 << '\n';
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    for (int i = 1; i <= m; ++i) {
      int temp;
      std::cin >> temp;
      if (i & 1) {
        max_heap.push(temp);
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
          min_heap.push(max_heap.top());
          max_heap.pop();
          max_heap.push(min_heap.top());
          min_heap.pop();
        }
        std::cout << max_heap.top() << ' ';
        if (max_heap.size() == 10)
          std::cout << '\n';
      } else {
        min_heap.push(temp);
      }
    }
    std::cout << '\n';
  }

  return 0;
}
