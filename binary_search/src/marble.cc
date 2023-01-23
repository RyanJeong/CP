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

  // 최적화 문제:
  // * 보석을 어린이에게 나누어줄 때, 한 어린이가 표현할 수 있는 최소 질투 지수
  // 결정 문제:
  // * 보석을 x개씩 나누어줬을 때의 대상 수가 n개 이하인가? (최소)
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(m);
  for (int i = 0; i < m; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int low = 1;
  int high = v.back() + 1;  // [low, high)
  while (low < high) {
    int mid = (high + low) / 2;
    int cnt = 0;
    for (const int& i : v) {
      cnt += i / mid;
      if (i % mid)
        ++cnt;
    }

    if (cnt <= n)
      high = mid;
    else
      low = mid + 1;
  }
  std::cout << high;

  return 0;
}
