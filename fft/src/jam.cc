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

const double kPi = std::acos(-1);

// implement it if you need
template <typename T>
void PostProcess(std::vector<std::complex<T>>* f) {
  if (!f)
    return;

  // post-process to reduce errors due to precision
  for (int i = 0; i < f->size(); ++i) {
    f->at(i) = std::complex<T>{
        static_cast<T>(std::round(f->at(i).real()) ? 1 : 0), 0};
  }
}

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

  // PostProcess(nullptr);
  PostProcess(a);
}

int main() {
  CP;

  int n, k;
  std::cin >> n >> k;
  std::vector<int> v(1001);  // 1-based
  while (n--) {
    int idx;
    std::cin >> idx;
    ++v[idx];
  }

  std::vector<std::complex<double>> a(1, 1);
  std::vector<std::complex<double>> b(v.begin(), v.end());
  for (; k; k >>= 1) {
    if (k & 1) {
      // if you use b, b will be doubled in size
      std::vector<std::complex<double>> temp(b);
      Multiply(&a, &temp);
      if (k == 1)
        break;
    }
    Multiply(&b, &b);
  }

  for (int i = 1; i < a.size(); ++i) {
    if (std::round(a[i].real()))
      std::cout << i << ' ';
  }

  return 0;
}
