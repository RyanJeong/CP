/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/
#include <iostream>
#include <string>
#include <queue>

int main() {
  std::string a, b;
  std::cin >> a >> b;

  const int cnt[] = {
    3, 2, 1, 2, 3, 3, 2, 3, 3, 2,
    2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
    1, 1, 1, 2, 2, 1
  };
  std::queue<int> q, tmp;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    q.push(cnt[a[i]-'A']);
    q.push(cnt[b[i]-'A']);
  }
  while (q.size() > 2) {
    int prev = q.front();
    q.pop();
    while (!q.empty()) {
      int sum = prev + q.front();
      tmp.push(sum % 10);
      prev = q.front();
      q.pop();
    }
    q = tmp;
    tmp = std::queue<int>();  // Init.
  }
  std::cout << q.front();
  q.pop();
  std::cout << q.front();

  return 0;
}

