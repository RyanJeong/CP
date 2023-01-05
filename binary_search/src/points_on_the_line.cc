/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
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

  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  while (m--) {
    int a, b;
    std::cin >> a >> b;
    int lower = std::lower_bound(v.begin(), v.end(), a) - v.begin();
    int upper = std::upper_bound(v.begin(), v.end(), b) - v.begin();
    std::cout << upper - lower << '\n';
  }

  return 0;
}
