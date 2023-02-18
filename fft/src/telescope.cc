/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>

const double kPi = std::acos(-1);

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

        std::complex<T> temp = p_w * f->at(i + j + k);  // w * f_odd(w^2)
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

  int n, l, m;
  int64_t w;  // 3e3 * 1e2 * 1e4
  std::cin >> n >> l >> m >> w;
  std::vector<std::vector<int>> p(m, std::vector<int>(n));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
      std::cin >> p[i][j];
  }
  std::vector<std::vector<int>> t(m, std::vector<int>(l));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < l; ++j)
      std::cin >> t[i][j];
    std::reverse(t[i].begin(), t[i].end());
  }

  std::vector<std::vector<int>> res;  // c_3000 = (100 * 100) x 3000
  for (int i = 0; i < m; ++i) {
    std::vector<std::complex<double>> a(p[i].begin(), p[i].end());
    std::vector<std::complex<double>> b(t[i].begin(), t[i].end());
    Multiply(&a, &b);
    std::vector<int> temp;
    for (int i = 0; i < a.size(); ++i)
      temp.push_back(std::round(a[i].real()));
    res.push_back(temp);
  }

  int ans = 0;
  // sum col's values => 1, 2, ..., k pos's intensity
  for (int j = l - 1; j < n; ++j) {
    int64_t temp = 0;
    for (int i = 0; i < m; ++i)
      temp += res[i][j];
    if (temp > w)
      ++ans;
  }
  std::cout << ans;

  return 0;
}
