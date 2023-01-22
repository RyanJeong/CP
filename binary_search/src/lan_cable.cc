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

  // 최적화 문제: 랜선 n개를 만들 때 각 랜선의 최대 길이
  // 결정 문제: 각 랜선의 길이가 x일 때, 랜선이 n개 이상인가? (최대)
  int k, n;
  std::cin >> k >> n;
  std::vector<int> v(k);
  for (int i = 0; i < k; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int res = 0;
  int64_t low = 1;
  int64_t high = static_cast<int64_t>(v.back()) + 1;  // [low, high)
  while (low < high) {
    int64_t mid = (low + high) / 2;
    int cnt = 0;
    for (const int& l : v)
      cnt += l / mid;

    if (cnt >= n) {
      low = mid + 1;
      res = mid;
    } else {
      high = mid;
    }
  }
  std::cout << res;

  return 0;
}
