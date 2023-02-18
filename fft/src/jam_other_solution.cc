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
        f->at(i + j + k) = f->at(j + k) - temp;         // f(-w)
        f->at(j + k) += temp;                           // f(w)
        p_w *= w;
      }
    }
  }

  if (!inv)
    return;
  for (int i = 0; i < n; ++i)
    f->at(i) /= n;
}

template <typename T1, typename T2>
std::vector<T1> Multiply(const std::vector<T1>& a,
                         const std::vector<T1>& b) {
  std::vector<std::complex<T2>> f, g;
  f = std::vector<std::complex<T2>>(a.begin(), a.end());
  if (&a != &b)
    g = std::vector<std::complex<T2>>(b.begin(), b.end());

  int n = std::max(a.size(), b.size()) << 1;
  int i = 0;
  while (n > (1 << i))  // fit n to 2^p
    ++i;
  n = 1 << i;  // get w^2

  f.resize(n);
  if (&a != &b)
    g.resize(n);

  // DFT
  Fft(&f, false);
  if (&a != &b)
    Fft(&g, false);

  // convolution
  if (&a != &b) {
    for (int i = 0; i < n; ++i)
      f[i] *= g[i];
  } else {
    for (int i = 0; i < n; ++i)
      f[i] *= f[i];
  }

  // IDFT
  Fft(&f, true);

  std::vector<T1> ret(n);
  for (int i = 0; i < n; ++i)
    ret[i] = std::round(f[i].real());

  return ret;
}

int main() {
  CP;

  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(1001);  // 1-based
  while (n--) {
    int idx;
    std::cin >> idx;
    v[idx] = 1;
  }

  std::vector<int> u(1, 1);
  for (; k; k >>= 1) {
    if (k & 1) {
      u = Multiply<int, double>(u, v);

      // post-process to reduce errors due to precision
      for (int i = 0; i < u.size(); ++i)
        u[i] = u[i] ? 1 : 0;

      if (k == 1)
        break;
    }
    v = Multiply<int, double>(v, v);

    // post-process to reduce errors due to precision
    for (int i = 0; i < v.size(); ++i)
      v[i] = v[i] ? 1 : 0;
  }

  for (int i = 1; i < u.size(); ++i) {
    if (u[i])
      std::cout << i << ' ';
  }

  return 0;
}
