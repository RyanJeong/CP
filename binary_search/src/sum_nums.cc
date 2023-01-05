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

  // a + b + c = max <-> a + b = max - c
  std::vector<int> tmp;
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j)
      tmp.push_back(v[i] + v[j]);
  }
  sort(tmp.begin(), tmp.end());

  // a + b = max - c
  // tmp = a + b, v[i]: max, v[j]: c
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < n; ++j) {
      if (binary_search(tmp.begin(), tmp.end(), v[i] - v[j])) {
        std::cout << v[i];

        return 0;
      }
    }
  }

  return 0;
}
