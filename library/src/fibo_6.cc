/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

/*
 * https://mathworld.wolfram.com/FibonacciQ-Matrix.html
 * f(n) = f(n-1) + f(n-2)
 * => [f(n)] = [1 1][f(n-1) f(n-2)]^T
 *
 * f(n-1) = f(n-1)
 * => [f(n-1)] = [1 0][f(n-1) f(n-2)]^T <- dummy for 2x2 matrix
 *
 * =>
 *
 * f(n)   = f(n-1) + f(n-2)
 * f(n-1) = f(n-1) + 0
 *
 * n = 2
 * f(2) = {1 1}{f(1)} = {1}
 * f(1) = {1 0}{f(0)}   {0}
 *
 * n = 3
 * f(3) = {1 1}{f(2)}    {1 1}^2{1}
 * f(2) = {1 0}{f(1)} = >{1 0}  {0}
 * ...
 * => n = {1 1}^n-1{1}
 *        {1 0}    {0}
 *
 * if A = {1 1} = {f(2) f(1)}
 *        {1 0}   {f(1) f(0)}
 * then
 * A^2 = {1+1 1+0} = {2 1} = {f(3) f(2)}
 *       {1+0 1+0}   {1 1}   {f(2) f(1)}
 * A^3 = {2+1 2+0} = {3 2} = {f(4) f(3)}
 *       {1+1 1+0}   {2 1}   {f(3) f(2)}
 *
 * rule 1: a_11 = {a_21 | a_12} + a_22
 * rule 2: a_12 == a_21
 *
 * =>
 *
 * A^n = {f(n+1}  f(n) } = f(n)
 *       { f(n)  f(n-1)}
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
      temp[i][j] %= 1000000007;
    }
  }

  return temp;
}

int main() {
  CP;

  int64_t n;
  std::cin >> n;
  std::vector<std::vector<int64_t>> a{{1, 1}, {1, 0}};
  std::vector<std::vector<int64_t>> res{{1, 0}, {0, 1}};
  for (; n; n >>= 1) {
    if (n & 1)
      res = MatMul(res, a, 2);
    a = MatMul(a, a, 2);
  }
  std::cout << res[0][1];

  return 0;
}
