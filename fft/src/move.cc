/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// x: { a, b, c, d}, y: { e, f, g, h}
//    {x0 x1 x2 x3}     {y0 y1 y2 y3}
// -> x`: {a, b, c, d, a, b, c, d}
// -> y`: {h, g, f, e, 0, 0, 0, 0}, n = 8
// c's length: 2n-1 = 15(c0 ~ c14)
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
#include <algorithm>

const double kPi = std::acos(-1);

void Fft(std::vector<std::complex<double>>* f,
         std::complex<double> w) {
  if (f->size() == 1)
    return;

  int n = f->size();
  std::vector<std::complex<double>> even(n / 2), odd(n / 2);
  for (int i = 0; i < n; ++i) {
    if (i & 1)
      odd[i/2] = f->at(i);
    else
      even[i/2] = f->at(i);
  }

  // f(x) = f_even(x^2) + (x * f_odd(x^2))
  Fft(&even, w * w);
  Fft(&odd, w * w);

  std::complex<double> p_w(1, 0);
  // f(w) = f_even(w^2) + (w * f_odd(w^2))
  // f(-w) = f_even(w^2) + (-w * f_odd(w^2))
  for (int i = 0; i < n / 2; ++i) {
    f->at(i) = even[i] + p_w * odd[i];
    f->at(i + n / 2) = even[i] - p_w * odd[i];
    p_w *= w;
  }
}

std::vector<std::complex<double>> PolyMul(
    std::vector<std::complex<double>>* a,
    std::vector<std::complex<double>>* b) {
  int n = 1;
  while (n < a->size() + 1 ||
         n < b->size() + 1) {
    n *= 2;
  }
  n *= 2;  // set the coefficients to 0 after doubling n
  a->resize(n);
  b->resize(n);

  // DFT
  std::vector<std::complex<double>> c(n);
  std::complex<double> w(std::cos(2 * kPi / n), std::sin(2 * kPi / n));
  Fft(a, w);
  Fft(b, w);

  for (int i = 0; i < n; ++i)
    c[i] = a->at(i) * b->at(i);

  // IDFT
  Fft(&c, std::complex<double>(1, 0) / w);
  for (int i = 0; i < n; ++i) {
    c[i] /= std::complex<double>(n, 0);
    c[i] = std::complex<double>(std::round(c[i].real()),
                                std::round(c[i].imag()));
  }

  return c;
}

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<int> v_a(n * 2);
  for (int i = 0; i < n; ++i) {
    std::cin >> v_a[i];
    v_a[i+n] = v_a[i];
  }
  std::vector<int> v_b(n * 2);
  for (int i = n - 1; i >= 0; --i)
    std::cin >> v_b[i];

  std::vector<std::complex<double>> a;
  for (const int& i : v_a)
    a.push_back(std::complex<double>(i, 0));
  std::vector<std::complex<double>> b;
  for (const int& i : v_b)
    b.push_back(std::complex<double>(i, 0));

  std::vector<std::complex<double>> c = PolyMul(&a, &b);
  int res = -1;
  for (int i = n; i < 2 * n; ++i)  // (0, n), (1, n-1), ... , (n-1, 1), (n, 0)
    res = std::max(res, static_cast<int>(c[i].real()));
  std::cout << res;

  return 0;
}
