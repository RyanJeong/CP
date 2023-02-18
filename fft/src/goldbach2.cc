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

template<typename T>
std::vector<int> EratosthenesSieve(T from, T to) {
  static std::vector<bool> is_composition(to + 1);  // 1-based

  if (from < 2)  // 1 is not a prime number
    from = 2;
  for (T i = 2; i * i <= to; ++i) {
    if (is_composition[i])
      continue;
    for (T j = i * i; j <= to; j += i)
      is_composition[j] = true;
  }

  std::vector<int> primes;
  for (T i = from; i <= to; ++i) {
    if (!is_composition[i])
      primes.push_back(i);
  }

  return primes;
}

int main() {
  CP;

  const int kMaxSize = 1000000;
  auto primes = EratosthenesSieve(static_cast<int64_t>(2),
                                  static_cast<int64_t>(kMaxSize));

  std::vector<std::complex<double>> a(kMaxSize + 1);  // 1-based
  for (const int& i : primes)
    a[i] = std::complex<double>{1, 0};

  Multiply(&a, &a);

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int res = std::round(a[n].real());
    // If the result is odd, `1` is reduced in the process of dividing by `2`,
    // so `1` must be added again.
    std::cout << (res & 1 ? res / 2 + 1 : res / 2) << '\n';
  }

  return 0;
}
