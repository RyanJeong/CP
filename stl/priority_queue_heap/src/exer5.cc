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
  std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  while (n--) {
    int temp;
    std::cin >> temp;

    if (max_heap.size() <= min_heap.size())
      max_heap.push(temp);
    else
      min_heap.push(temp);

    if (!max_heap.empty() && !min_heap.empty() &&
        max_heap.top() > min_heap.top()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    std::cout << max_heap.top() << '\n';
  }

  return 0;
}
