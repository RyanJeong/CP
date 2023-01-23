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

  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];

  int64_t low = 1;
  int64_t high = 2e9 + 1;  // [low, high)
  while (low < high) {
    int64_t mid = (low + high) / 2;
    int64_t cnt = 0;
    for (const int& l : v) {
      if (mid < l)
        continue;
      cnt += mid - l;
    }

    if (cnt <= k)  // cnt가 더 적거나 같음
                   // -> mid 값을 높여야 cnt 개수를 늘릴 수 있음
      low = mid + 1;
    else
      high = mid;
  }
  std::cout << low - 1;

  return 0;
}
