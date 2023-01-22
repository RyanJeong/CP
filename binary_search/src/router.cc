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

  // 최적화 문제: 두 공유기 사이의 거리를 최대로
  // 결정 문제: 각 공유기 간 거리가 x일 때, 공유기가 n개인가? (최대)
  int n, c;
  std::cin >> n >> c;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int res = 0;
  int low = 1;
  int high = v.back() - v.front() + 1;  // [low,high)
  while (low < high) {
    int mid = (low + high) / 2;
    int cnt = 1;
    int curr = v.front();
    for (int i = 1; i < n; ++i) {
      if (v[i] - curr >= mid) {
        ++cnt;
        curr = v[i];
      }
    }
    if (cnt >= c) {
      low = mid + 1;
      res = mid;
    } else {
      high = mid;
    }
  }
  std::cout << res;

  return 0;
}
