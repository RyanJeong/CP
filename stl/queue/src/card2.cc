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
  std::queue<int> q;
  for (int i = 1; i <= n; ++i)
    q.push(i);
  while (q.size() != 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }
  std::cout << q.front();

  return 0;
}
