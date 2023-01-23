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

  // 최적화 문제: n명 입국 심사 시 걸리는 최소 시간
  // 결정 문제: 입국심사가 x만큼 걸릴 때, n명 심사가 가능한가?
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int64_t low = 1;
  int64_t high = static_cast<int64_t>(v.back()) * m + 1;  // [low,high)
  while (low < high) {
    int64_t mid = (low + high) / 2;
    int64_t cnt = 0;
    for (const int& i : v)
      cnt += (mid / i);

    if (cnt >= m)
      high = mid;
    else
      low = mid + 1;
  }
  std::cout << high;

  return 0;
}
