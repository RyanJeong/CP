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

  int t;
  std::cin >> t;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i)
    std::cin >> a[i];
  int m;
  std::cin >> m;
  std::vector<int> b(m);
  for (int i = 0; i < m; ++i)
    std::cin >> b[i];

  for (int i = 0; i < n; ++i) {
    int tmp = a[i];
    for (int j = i + 1; j < n; ++j) {
      tmp += a[j];
      a.push_back(tmp);
    }
  }
  for (int i = 0; i < m; ++i) {
    int tmp = b[i];
    for (int j = i + 1; j < m; ++j) {
      tmp+=b[j];
      b.push_back(tmp);
    }
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  // 500,500 x 500,500
  int64_t res = 0;
  for (int i = 0; i < a.size(); ++i) {
    auto low = lower_bound(b.begin(), b.end(), t - a[i]);
    auto high = upper_bound(b.begin(), b.end(), t - a[i]);
    res += high - low;
  }
  std::cout << res;

  return 0;
}
