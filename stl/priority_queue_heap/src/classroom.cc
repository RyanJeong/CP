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
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i].first >> v[i].second;

  std::sort(v.begin(), v.end());
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  pq.push(-1);
  for (const auto& i : v) {
    auto& cur = pq.top();
    if (i.first >= cur)
      pq.pop();
    pq.push(i.second);
  }
  std::cout << pq.size();

  return 0;
}
