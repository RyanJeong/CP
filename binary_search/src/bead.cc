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

  // 결정문제: 그룹의 합이 mid일 때, 그룹의 개수가 x개인가?
  //         (그룹의 합 중 최대값이 최소가 되도록 해야 함)
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

  int low = max_val;   // 구슬 개수가 4개고, 그룹 수가 4개라면,
                       // 하한은 각 구슬 중 가장 큰 값
  int high = sum + 1;  // [low,high)
  while (low < high) {
    int mid = (low + high) / 2;
    int cnt = 1;  // 그룹의 합이 mid를 만족할 필요가 없으므로, 기본값은 1
    sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += v[i];
      if (sum > mid) {  // i == n - 1일 때 조건이 참이라면 sum은 하나의 그룹을 의미
                        // 조건이 거짓이라면, sum과 v[i] 각각 독립적인 그룹을 의미
        ++cnt;
        sum = v[i];
      }
    }

    if (cnt <= m)
      high = mid;
    else
      low = mid + 1;
  }
  std::cout << high << '\n';

  int size = 0;
  sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += v[i];
    if (sum > high) {
      std::cout << size << ' ';
      size = 0;
      sum = v[i];
      --m;
    }
    ++size;
    if (n - i == m)
      break;
  }
  while (m--) {
    std::cout << size << ' ';
    size = 1;
  }

  return 0;
}
