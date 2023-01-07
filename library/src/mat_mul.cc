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

template <typename T>
std::vector<std::vector<T>> MatMul(
    const std::vector<std::vector<T>>& a,  // 4 space indent
    const std::vector<std::vector<T>>& b,
    int size) {
  std::vector<std::vector<T>> temp(size, std::vector<T>(size));

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      for (int k = 0; k < size; ++k)
        temp[i][j] += a[i][k] * b[k][j];
      temp[i][j] %= 1000;
    }
  }

  return temp;
}

int main() {
  CP;

  int64_t n, b;
  std::cin >> n >> b;
  std::vector<std::vector<int64_t>> v(n, std::vector<int64_t>(n));
  std::vector<std::vector<int64_t>> res(n, std::vector<int64_t>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        res[i][j] = 1;
      std::cin >> v[i][j];
    }
  }

  for (; b; b >>= 1) {
    if (b & 1)
      res = MatMul(res, v, n);
    v = MatMul(v, v, n);
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      std::cout << res[i][j] << ' ';
    std::cout << '\n';
  }

  return 0;
}
