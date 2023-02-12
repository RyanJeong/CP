/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// idea: n > m
// n > m
// n : 3, m : 2
// {a, b, c}, {x, y} -> ax + by | bx + cy
// {a, b, c, 0, 0, 0}
// {y, x, 0, 0, 0, 0}
// c_1 = ax + by           => ax + by
// c_2 = a0 + bx + cy      => bx + cy
// c_3 = a0 + b0 + cx + 0y => cx, never bigger than others

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
#include <utility>
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

  int n, m;
  std::cin >> n >> m;
  std::string str_n;
  std::cin >> str_n;
  std::string str_m;
  std::cin >> str_m;
  std::reverse(str_m.begin(), str_m.end());

  std::vector<int> v_n(n);
  std::vector<int> v_m(m);
  std::vector<int> point(n);
  for (const auto& c : {
      std::pair<char, char>('R', 'P'),
      std::pair<char, char>('P', 'S'),
      std::pair<char, char>('S', 'R')}) {
    const char& c_n = c.first;
    for (int i = 0; i < n; ++i)
      v_n[i] = str_n[i] == c_n ? 1 : 0;

    const char& c_m = c.second;
    for (int i = 0; i < m; ++i)
      v_m[i] = str_m[i] == c_m ? 1 : 0;

    std::vector<std::complex<double>> a(v_n.begin(), v_n.end());
    std::vector<std::complex<double>> b(v_m.begin(), v_m.end());
    Multiply(&a, &b);

    for (int i = 0; i < n; ++i)
      point[i] += std::round(a[i+m-1].real());
  }

  int res = 0;
  for (const int& i : point)
    res = std::max(res, i);
  std::cout << res;

  return 0;
}
