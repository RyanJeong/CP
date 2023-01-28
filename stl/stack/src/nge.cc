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
#include <stack>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];

  std::vector<int> res(v.size(), -1);
  std::stack<int> s;
  for (int i = 0; i < v.size(); ++i) {
    while (!s.empty() && v[s.top()] < v[i]) {
      res[s.top()] = v[i];
      s.pop();
    }
    s.push(i);
  }
  for (const int& i : res)
    std::cout << i << ' ';

  return 0;
}
