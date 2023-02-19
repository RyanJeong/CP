/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea:
// 0 < a, b, c < n
// a^2 + b^2 ≡ c^2 (mod n) (a <= b)
// let i^2 % n => a_i
// then f(x) = a0 + a1x + a2x^2 + ... + an-1x^(n-1)
// f(x)^2 = a^2 + b^2
// ---
// 1. a < b (a^2 + b^2 <-> b^2 + a^2)
// 2. a = b (a^2 + a^2 = 2a^2)

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cmath>
#include <vector>
#include <complex>

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

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  std::vector<int> eq(n);
  for (int i = 1; i < n; ++i) {
    ++a[(static_cast<int64_t>(1)*i*i)%n];
    ++eq[(static_cast<int64_t>(2)*i*i)%n];  // a^2 + a^2 = 2a^2
  }
  std::vector<std::complex<double>> c(n);
  for (int i = 0; i < n; ++i)
    c[i] = std::complex<double>{static_cast<double>(a[i]), 0};

  Multiply(&c, &c);  // get a^2 + b^2
  // e.g. n = 7
  //   { 0, 2, 2, 0, 2, 0, 0 }
  // f(x)   = 2x + 2x^2 + 2x^4
  // f(x)^2 = 4x^2 + 8x^3 + 4x^4 + 8x^5 + 8x^6 + 4x^8
  // *** i % n = k, (i + n) % n = k ***
  int64_t res = 0;  // 499,998 => 441628740(overflow)
  for (int i = 1; i < n; ++i) {
    int idx = (static_cast<int64_t>(1) * i * i) % n;
    int cnt = std::round(c[idx].real()) + std::round(c[idx+n].real());

    // 1. rm n(a == b) and we can get n(a < b) when divice 2
    res += (cnt - eq[idx]) / 2;
    // 2. (a < b) + (a == b) => a <= b
    res += eq[idx];
  }
  std::cout << res;

  return 0;
}
