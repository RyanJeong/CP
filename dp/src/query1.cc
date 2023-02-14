/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// ex. n = 4 => {a, b, c, d}
// dp = {a, b, c, d}
// ----
// res[1] = a + b + c + d
// res[2] = a b + (a + b) c + (a + b + c) d
// res[3] = ab c + (a + b)c d
// res[4] = abc d

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>

int main() {
  CP;

  const int kModSize = 100003;
  int n;
  std::cin >> n;

  std::vector<int> v(n + 1);  // 1-based
  std::vector<int> dp(n + 1);
  std::vector<int> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> v[i];
    dp[i] = v[i];
    res[1] += v[i];  // res[1]
    if (res[1] >= kModSize)
      res[1] -= kModSize;
  }

  for (int i = 2; i <= n; ++i) {  // res[2..n]
    int temp = 0;
    for (int j = 1; j <= n - i + 1; ++j) {  // 1 ~ (n - 1), 1 ~ (n - 2), ... , 1
      temp += dp[j];
      if (temp >= kModSize)
        temp -= kModSize;
      dp[j] = (static_cast<int64_t>(temp) * v[i+j-1]) % kModSize;
      res[i] += dp[j];
      if (res[i] >= kModSize)
        res[i] -= kModSize;
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    std::cout << res[k] << '\n';
  }

  return 0;
}
