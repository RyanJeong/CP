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

  std::vector<std::complex<double>> c = PolyMul(&a, &b);

  int carry = 0;
  std::vector<int> res;
  for (int i = 0; i < c.size(); ++i) {
    int temp = c[i].real() + carry;
    res.push_back(temp % 10);
    carry = temp / 10;
  }
  while (carry) {
    res.push_back(carry % 10);
    carry /= 10;
  }

  while (res.back() == 0)
    res.pop_back();
  std::reverse(res.begin(), res.end());
  for (const auto& i : res)
    std::cout << i;

  return 0;
}
