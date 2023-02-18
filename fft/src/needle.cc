/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// The three barriers are the same length and the same spacing.
// =============  -> upper
//                 => gap(l)
// =============  -> middle
//                 => gap(l)
// =============  -> lower
// <-length(L)->
// ------
// ======C====== => ======/======
//                       /
// ====B======== => ====/========
//                     /
// ==A========== => ==/==========
// => B = (A + C) / 2
// e.g. a = 1, b = 2, c = 3;
// x * x^3 = x^4
// but we need to compare with 2 => need to divide with 2

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
         bool inv) {
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
    double x = inv ? kPi / i : -kPi / i;
    std::complex<double> w = {std::cos(x), std::sin(x)};
    for (int j = 0; j < n; j += (i << 1)) {
      std::complex<double> p_w = {1, 0};
      for (int k = 0; k < i; ++k) {
        // f(x) = f_even(x^2) + (x * f_odd(x^2))
        // f(w) = f_even(w^2) + (w * f_odd(w^2))
        // f(-w) = f_even(w^2) + (-w * f_odd(w^2))

        std::complex<double> temp = p_w * f->at(i + j + k);  // w * f_odd(w^2)
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

void Multiply(std::vector<std::complex<double>>* a,
              std::vector<std::complex<double>>* b) {
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

  int u;
  std::cin >> u;
  std::vector<std::complex<double>> upper(60001);
  while (u--) {
    int n;
    std::cin >> n;
    upper[n+30000] = std::complex<double>(1, 0);
  }

  int m;
  std::cin >> m;
  std::vector<std::complex<double>> middle(60001);
  while (m--) {
    int n;
    std::cin >> n;
    middle[n+30000] = std::complex<double>(1, 0);
  }

  int l;
  std::cin >> l;
  std::vector<std::complex<double>> lower(60001);
  while (l--) {
    int n;
    std::cin >> n;
    lower[n+30000] = std::complex<double>(1, 0);
  }

  Multiply(&upper, &lower);

  int res = 0;
  for (int i = 0; i < 60001; ++i)
    res += std::round(middle[i].real()) * std::round(upper[i*2].real());
  std::cout << res;

  return 0;
}
