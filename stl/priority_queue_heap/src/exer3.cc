/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <cmath>

int main() {
  CP;

  int n;
  std::cin >> n;
  // too much text to fit on one line:
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> min_heap;

  while (n--) {
    int x;
    std::cin >> x;

    if (!x) {
      if (min_heap.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << min_heap.top().second << '\n';
        min_heap.pop();
      }
    } else {
      min_heap.push({std::abs(x), x});
    }
  }

  return 0;
}
