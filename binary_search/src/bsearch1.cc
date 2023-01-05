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
    int target;
    std::cin >> target;

    auto low = v.begin();
    auto high = v.end();
    while (low < high) {
      auto mid = low + (high - low) / 2;
      if (target < *mid)
        high = mid;
      else if (target > *mid)
        low = mid + 1;
      else
        break;
    }
    std::cout << ((low < high) ? 1 : 0) << '\n';
  }

  return 0;
}
