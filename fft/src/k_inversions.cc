/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// approach:
// BABA
// ABAB <- reverse 'BABA'
//                        0 1 2 3
// {a0 a1 a2 a3 0 0 0 0} {b a b a 0 0 0 0}
// {b0 b1 b2 b3 0 0 0 0} {a b a b 0 0 0 0}
//                        3 2 1 0
// c0 = a0b0
//    = BABA   3-inversions
//      ^  ^   +1
// c1 = a0b1 + a1b0
//    = BABA   2-inversions
//      ^ ^    +0
//       ^ ^   +0
// c2 = a0b2 + a1b1 + a2b0
//    = BABA   1-inversions
//      ^^     +1
//       ^^    +0
//        ^^   +1
// c3 = a0b3 + a1b2 + a2b1 + a3b0
//    = BABA   0-inversions(ignored)
//      ^
//       ^
//        ^
//         ^

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
#include <string>

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

  std::string str;
  std::cin >> str;
  std::vector<std::complex<double>> a(str.length());
  for (int i = 0; i < str.length(); ++i) {
    a[i] = std::complex<double>{
        static_cast<double>(str[i] == 'B' ? 1 : 0), 0};
  }
  std::reverse(str.begin(), str.end());
  std::vector<std::complex<double>> b(str.length());
  for (int i = 0; i < str.length(); ++i) {
    b[i] = std::complex<double>{
        static_cast<double>(str[i] == 'A' ? 1 : 0), 0};
  }

  Multiply(&a, &b);

  for (int i = str.length() - 2; i >= 0; --i)
    std::cout << static_cast<int>(std::round(a[i].real())) << '\n';

  return 0;
}
