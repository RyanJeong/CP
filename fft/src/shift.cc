/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// x: { a, b, c, d}, y: { e, f, g, h}
//    {x0 x1 x2 x3}     {y0 y1 y2 y3}
// -> x`: {a, b, c, d, a, b, c, d}
// -> y`: {h, g, f, e, 0, 0, 0, 0}, n = 8
// c0 = x`0y`0
//    = ah
// c1 = x`0y`1 + x`1y`0
//    = ag + bh
// c2 = x`0y`2 + x`1y`1 + x`2y`0
//    = af + bg + ch
// c3 = x`0y`3 + x`1y`2 + x`2y`1 + x`3y`0
//    = ae + bf + cg + dh
//    = x0y0 + x1y1 + x2y2 + x3y3
// c4 = x`0y`4 + x`1y`3 + x`2y`2 + x`3y`1 + x`4y`0
//    = 0 + be + cf + dg + ah
//    = x1y0 + x2y1 + x4y2 + x0y3
// c5 = x`0y`5 + x`1y`4 + x`2y`3 + x`3y`2 + x`4y`1 + x`5y`0
//    = 0 + 0 + ce + df + ag + bg
//    = x2y0 + x3y1 + x0y2 + x1y3
// c6 = x`0y`6 + x`1y`5 + x`2y`4 + x`3y`3 + x`4y`2 + x`5y`1 + x`6y`0
//    = 0 + 0 + 0 + de + af + bg + ch
//    = x3y0 + x0y1 + x1y2 + x2y3
// c7 = x`0y`7 + x`1y`6 + x`2y`5 + x`3y`4 + x`4y`3 + x`5y`2 + x`6y`1 + x`7y`0
//    = 0 + 0 + 0 + 0 + ae + bf + cg + dh
//    = x0y0 + x1y1 + x2y2 + x3y3
// ...
// => DFT -> convolution -> IDFT -> std::max

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
#include <string>
#include <algorithm>

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

  std::string s;
  std::cin >> s;
  s += s;
  std::vector<std::complex<double>> a(s.length());
  for (int i = 0; i < s.length(); ++i)
    a[i] = std::complex<double>(s[i] - '0', 0);

  std::string t;
  std::cin >> t;
  std::reverse(t.begin(), t.end());
  std::vector<std::complex<double>> b(s.length());
  for (int i = 0; i < t.length(); ++i)
    b[i] = std::complex<double>(t[i] - '0', 0);

  Multiply(&a, &b);

  int res = -1;
  for (int i = t.length(); i < 2 * t.length(); ++i)
    res = std::max(res, static_cast<int>(std::round(a[i].real())));
  std::cout << res;

  return 0;
}
