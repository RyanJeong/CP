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

  // 결정문제: mid만큼 파를 넣었을 때, cnt 개수가 c인가?(파의 길이는 최대)
  int s, c;
  std::cin >> s >> c;
  std::vector<int> v(s);
  for (int i = 0; i < s; ++i)
    std::cin >> v[i];
  std::sort(v.begin(), v.end());

  int64_t low = 1;
  int64_t high = v.back() + 1;  // [low, high)
  while (low < high) {
    int64_t mid = (low + high) / 2;
    int64_t cnt = 0;
    for (const int& l : v)
      cnt += l / mid;

// std::cout << cnt << ' ' << mid << '\n';
    if (cnt >= c)
      low = mid + 1;
    else
      high = mid;
  }
  int64_t res = 0;
  for (const auto& i : v) {
    if (c >= i / (low - 1)) {
      res += i % (low - 1);
      c -= i / (low - 1);
    } else if (c) {
      res += (i - c * (low - 1));
      c = 0;
    } else {
      res += i;
    }
  }
  std::cout << res;

  return 0;
}
