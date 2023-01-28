/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <utility>
#include <deque>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::deque<std::pair<int, int>> dq;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    std::cin >> tmp;
    dq.push_back({i, tmp});
  }

  auto cur = dq.front();
  dq.pop_front();
  std::cout << cur.first << ' ';
  while (!dq.empty()) {
    if (cur.second > 0) {
      while (cur.second--) {
        dq.push_back(dq.front());
        dq.pop_front();
      }
      cur = dq.back();
      dq.pop_back();
    } else {
      while (cur.second++) {
        dq.push_front(dq.back());
        dq.pop_back();
      }
      cur = dq.front();
      dq.pop_front();
    }
    std::cout << cur.first << ' ';
  }

  return 0;
}
