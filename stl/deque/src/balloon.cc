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

// iostream
using std::cin;
using std::cout;

// utility
using std::pair;

// deque
using std::deque;

int main() {
  CP;

  int n;
  cin >> n;
  deque<pair<int, int>> dq;
  for (int i = 1; i <= n; ++i) {
    int tmp;
    cin >> tmp;
    dq.push_back({i, tmp});
  }

  auto cur = dq.front();
  dq.pop_front();
  cout << cur.first << ' ';
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
    cout << cur.first << ' ';
  }

  return 0;
}
