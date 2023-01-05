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

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int m;
  std::cin >> m;
  while (m--) {
    int t;
    std::cin >> t;
    auto upper = std::upper_bound(v.begin(), v.end(), t);
    auto lower = std::lower_bound(v.begin(), v.end(), t);
    std::cout << upper - lower << ' ';
  }

  return 0;
}
