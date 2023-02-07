# FFT
* 추천문제 - Cooley-Tukey algorithm
  * [[BOJ] 큰 수 곱셈 (2)](https://www.acmicpc.net/problem/15576) [(소스코드)](./src/exam.cc)
  * [[BOJ] 이동](https://www.acmicpc.net/problem/1067) [(소스코드)](./src/move.cc)
  * [[WIP][BOJ] Golf Bot](https://www.acmicpc.net/problem/10531) [(소스코드)](./src/golf_bot.cc)

* 추천문제 - 최적화된 FFT
  * [[BOJ] 큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289) [(소스코드)](./src/exam_opt.cc) - 시간초과 해결해야 함(FFT 최적화)

## FFT
* [Cooley-Tukey algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm) (시간복잡도: <b>O(nlogn)</b>)

### 연습문제
* [[BOJ] 큰 수 곱셈](https://www.acmicpc.net/problem/13277) [(소스코드)](./src/exam.cc)

```c++
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

```

* [Cooley-Tukey algorithm](https://en.wikipedia.org/wiki/Cooley%E2%80%93Tukey_FFT_algorithm) 비재귀 방법 (시간복잡도: <b>O(nlogn)</b>)

### 연습문제
* [[BOJ] 큰 수 곱셈 (3)](https://www.acmicpc.net/problem/22289) [(소스코드)](./src/exam_opt.cc)

```c++
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

```