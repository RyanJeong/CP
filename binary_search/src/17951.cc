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

  // 결정문제: 그룹의 합이 mid일 때, 그룹의 개수가 x개인가?
  //         (그룹의 합 중 최소값이 최대가 되도록 해야 함)
  int n, m;
  std::cin >> n >> m;
  std::vector<int> v(n);
  int sum = 0;
  int max_val = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    sum += v[i];
    max_val = std::max(max_val, v[i]);
  }

  int low = max_val;
  int high = sum + 1;
  while (low < high) {
    int mid = (low + high) / 2;
    int cnt = 0;  // 그룹의 합이 mid를 만족해야 하므로, 기본값은 0
    sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += v[i];
      if (sum >= mid) {  // i == n - 1일 때, 그룹의 합이 mid를 만족하는가? (>=)
        ++cnt;
        sum = 0;
      }
    }

    if (cnt >= m)
      low = mid + 1;
    else
      high = mid;
  }
  std::cout << low - 1;

  return 0;
}
