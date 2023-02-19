/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// c_5 = a_0b_5 + a_1b_4 + ... + a_4b_1 + a_5b_0
// if coefficient is 0 -> operand will be ignored

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

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

  int n;
  std::cin >> n;

  std::vector<std::complex<double>> v(200001);
  v[0] = std::complex<double>{1, 0};  // c_5 = a_0b_5 + ... + a_5b_0
  for (int i = 0; i < n; ++i) {
    int idx;
    std::cin >> idx;
    v[idx] = std::complex<double>{1, 0};
  }

  Multiply(&v, &v);

  int m;
  std::cin >> m;
  int res = 0;
  for (int i = 0; i < m; ++i) {
    int idx;
    std::cin >> idx;
    if (std::round(v[idx].real()) > 0)
      ++res;
  }
  std::cout << res;

  return 0;
}
