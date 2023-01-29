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


int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> v;
  while (n--) {
    int p, d;
    std::cin >> p >> d;
    v.push_back({d, p});
  }
  std::sort(v.begin(), v.end());

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for (const auto& curr : v) {
    pq.push(curr.second);
    if (pq.size() > curr.first)
      pq.pop();
  }

  int res = 0;
  while (!pq.empty()) {
    res += pq.top();
    pq.pop();
  }
  std::cout << res;

  return 0;
}
