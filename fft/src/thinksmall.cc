/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// 1. 1,000,000 ^ 2 = 1e12 > MAX_INT
//    => int64_t
// 2. double(fail) => long double
// 3. split the op by two ops(2^20 => 1^10 + 1^10)
// xy = (x1 X 2^10 + x2)(y1 X 2^10 + y2)
//    = (x1y1) X 2^20 + (x1y2 + x2y1) X 2^10 + x2y2

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <utility>

const long double kPi = std::acos(-1);

template <typename T>
void Fft(std::vector<std::complex<T>>* f, bool inv) {
  int n = f->size();
  for (int i = 1, j = 0; i < n; ++i) {
    int b = n >> 1;
    // bit reversal
    while (!((j ^= b) & b))
      b >>= 1;
    if (i < j)
      std::swap(f->at(i), f->at(j));
  }

  for (int i = 1; i < n; i <<= 1) {
    T x = inv ? kPi / i : -kPi / i;
    std::complex<T> w = {std::cos(x), std::sin(x)};
    for (int j = 0; j < n; j += (i << 1)) {
      std::complex<T> p_w = {1, 0};
      for (int k = 0; k < i; ++k) {
        // f(x) = f_even(x^2) + (x * f_odd(x^2))
        // f(w) = f_even(w^2) + (w * f_odd(w^2))
        // f(-w) = f_even(w^2) + (-w * f_odd(w^2))

        std::complex<T> temp
            = p_w * f->at(i + j + k);            // w * f_odd(w^2)
        f->at(i + j + k) = f->at(j + k) - temp;  // f(-w)
        f->at(j + k) += temp;                    // f(w)
        p_w *= w;
      }
    }
  }

  if (!inv)
    return;
  for (int i = 0; i < n; ++i)
    f->at(i) /= n;
}

template <typename T>
void Multiply(std::vector<std::complex<T>>* a,
              std::vector<std::complex<T>>* b) {
  int n = std::max(a->size(), b->size()) << 1;
  int i = 0;
  while (n > (1 << i))  // fit n to 2^p
    ++i;
  n = 1 << i;  // get w^2

  a->resize(n);
  if (a != b)
    b->resize(n);

  // DFT
  Fft(a, false);
  if (a != b)
    Fft(b, false);

  // convolution
  for (int i = 0; i < n; ++i)
    a->at(i) *= b->at(i);

  // IDFT
  Fft(a, true);
}

int main() {
  CP;

  int n, m;
  std::cin >> n >> m;
  std::vector<int64_t> v_a(n + 1);
  for (int i = 0; i <= n; ++i)
    std::cin >> v_a[i];
  std::vector<int64_t> v_b(m + 1);
  for (int i = 0; i <= m; ++i)
    std::cin >> v_b[i];

  std::vector<std::vector<int64_t>> res;
  for (const auto& i : {  // true: lower 10-bit, false: upper 10-bit
      std::pair<bool, bool>(true, true),
      std::pair<bool, bool>(true, false),
      std::pair<bool, bool>(false, true),
      std::pair<bool, bool>(false, false)}) {
    const bool& is_a_lower = i.first;
    const bool& is_b_lower = i.second;

    std::vector<std::complex<long double>> a;
    for (const auto& i : v_a)
      a.push_back(std::complex<long double>(
          (is_a_lower ? i & ((1 << 10) - 1) : i >> 10), 0));
    std::vector<std::complex<long double>> b;
    for (const auto& i : v_b)
      b.push_back(std::complex<long double>(
          (is_b_lower ? i & ((1 << 10) - 1) : i >> 10), 0));
    Multiply(&a, &b);

    std::vector<int64_t> temp;
    for (const auto& i : a)
      temp.push_back(std::round(i.real()));
    res.push_back(temp);
  }
  int64_t ans = 0;
  for (int i = 0; i <= n + m; ++i)  // x^2 X x^2 = x^4 = 0, 1, 2, 3, 4
    ans ^= (res[3][i] << 20) + ((res[2][i] + res[1][i]) << 10) + res[0][i];
  std::cout << ans;

  return 0;
}
