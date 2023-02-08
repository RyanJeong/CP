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
#include <string>

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
  b->resize(n);

  // DFT
  Fft(a, false);
  Fft(b, false);

  // convolution
  for (int i = 0; i < n; ++i)
    a->at(i) *= b->at(i);

  // IDFT
  Fft(a, true);
}

int main() {
  CP;

  std::string str_a;
  std::cin >> str_a;
  if (str_a == "0") {
    std::cout << '0';

    return 0;
  }

  std::string str_b;
  std::cin >> str_b;
  if (str_b == "0") {
    std::cout << '0';

    return 0;
  }

  std::reverse(str_a.begin(), str_a.end());
  std::vector<std::complex<double>> a;
  for (const char& i : str_a)
    a.push_back(std::complex<double>(i - '0', 0));

  std::reverse(str_b.begin(), str_b.end());
  std::vector<std::complex<double>> b;
  for (const char& i : str_b)
    b.push_back(std::complex<double>(i - '0', 0));

  Multiply(&a, &b);

  std::vector<int> res(a.size());
  for (int i = 0; i < res.size(); ++i)
    res[i] = std::round(a[i].real());

  for (int i = 0; i < res.size(); ++i) {
    if (res[i] < 10)
      continue;

    if (i < res.size() - 1)
      res[i+1] += res[i] / 10;
    else
      res.push_back(res[i] / 10);
    res[i] %= 10;
  }
  while (res.back() == 0)
    res.pop_back();
  std::reverse(res.begin(), res.end());

  for (const int& i : res)
    std::cout << i;

  return 0;
}