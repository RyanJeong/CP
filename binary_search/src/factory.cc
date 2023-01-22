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
#include <algorithm>
#include <queue>
#include <functional>

int main() {
  CP;

  int n, x;
  std::cin >> n >> x;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];

  int low = 1;
  int high = n + 1;  // [low,high)
  while (low < high) {
    int mid = (low + high) / 2;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < mid; ++i)
      pq.push(0);

    bool is_possible = true;
    for (int i = 0; i < n; ++i) {
      auto curr = pq.top();
      pq.pop();
      if (curr + v[i] > x) {
        is_possible = false;
        break;
      }
      pq.push(curr + v[i]);
    }

    if (!is_possible)
      low = mid + 1;
    else
      high = mid;
  }
  std::cout << high;

  return 0;
}
