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

  int n, m;
  std::cin >> n >> m;  // 1 ~ n -> 1-based
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  std::vector<std::vector<int>> v(n + 1, std::vector<int>());
  std::vector<int> cnt_lock(n + 1);
  while (m--) {
    int s, t;
    std::cin >> s >> t;
    v[s].push_back(t);
    ++cnt_lock[t];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt_lock[i])
      continue;
    pq.push(i);
  }
  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    std::cout << curr << ' ';
    for (const int& i : v[curr]) {
      --cnt_lock[i];
      if (cnt_lock[i])
        continue;
      pq.push(i);
    }
  }

  return 0;
}
