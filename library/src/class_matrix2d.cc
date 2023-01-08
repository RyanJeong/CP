/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

/* Fast Power Algorithm
 * s(n) = A^n + A^n-1 + ... + A^2 + A^1
 * n = 1 -> A
 * n = 2 -> A^2 + A
 *       => A(A + I)
 *       => s(1)(A + I)
 * n = 3 -> A^3 + A^2 + A
 *       => A^3 + A(A + I)
 *       => A^3 + s(1)(A + I)
 * n = 4 -> A^4 + A^3 + A^2 + A
 *       => A^2(A^2 + A) + A^2 + A
 *       => (A^2 + A)(A^2 + I)
 *       => s(2)(A^2 + I)
 * n = 5 -> A^5 + A^4 + A^3 + A^2 + A
 *       => A^5 + (A^2 + A)(A^2 + I)
 *       => A^5 + s(2)(A^2 + I)
 *
 * odd  => A^n + s(n/2)(A^n/2 + I)
 * even => s(n/2)(A^n/2 + I)
 */

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cassert>
#include <vector>

template <typename T>
class Matrix2d {
  size_t size_;
  std::vector<std::vector<T>> m_;

 public:
  explicit Matrix2d(size_t n = 2)
      : size_(n), m_(n, std::vector<T>(n)) {  // 4 spaces
    for (size_t i = 0; i < size_; ++i)
      m_[i][i] = 1;
  }
  ~Matrix2d() = default;

  const size_t GetSize() const {
    return size_;
  }

  const friend Matrix2d<T> operator+(
      const Matrix2d<T>& a,
      const Matrix2d<T>& b) {
    if (a.GetSize() != b.GetSize())
      assert(false);

    size_t n = a.GetSize();
    Matrix2d<T> temp(n);
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        temp[i][j] = a[i][j] + b[i][j];
        // if the problem is tight on value limits:
        temp[i][j] %= 1000;
      }
    }

    return temp;
  }
  const friend Matrix2d<T> operator-(
      const Matrix2d<T>& a,
      const Matrix2d<T>& b) {
    if (a.GetSize() != b.GetSize())
      assert(false);

    size_t n = a.GetSize();
    Matrix2d temp(n);
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        temp[i][j] = a[i][j] - b[i][j];
        // if the problem is tight on value limits:
        // temp[i][j] %= 1000;
      }
    }

    return temp;
  }
  const friend Matrix2d<T> operator*(
      const Matrix2d<T>& a,
      const Matrix2d<T>& b) {
    if (a.GetSize() != b.GetSize())
      assert(false);

    size_t n = a.GetSize();
    Matrix2d<T> temp(n);
    for (size_t i = 0; i < n; ++i) {
      for (size_t j = 0; j < n; ++j) {
        T elem = 0;
        for (size_t k = 0; k < n; ++k)
          elem += a[i][k] * b[k][j];
        temp[i][j] = elem;
        // if the problem is tight on value limits:
        temp[i][j] %= 1000;
      }
    }

    return temp;
  }
  // TODO(munseong): need to implement it when it's needed
  // const friend Matrix2d<T> operator/(
  //     const Matrix2d<T>& a,
  //     const Matrix2d<T>& b)

  // Accessor
  const std::vector<T>& operator[] (size_t idx) const {
    if (idx < 0 || idx >= size_)
      assert(false);

    return m_[idx];
  }
  // Mutator
  std::vector<T>& operator[] (size_t idx) {
    if (idx < 0 || idx >= size_)
      assert(false);

    return m_[idx];
  }
  Matrix2d<T>& operator=(const Matrix2d<T>& m) {
    if (size_ != m.GetSize())
      assert(false);

    for (size_t i = 0; i < size_; ++i) {
      for (size_t j = 0; j < size_; ++j)
        m_[i][j] = m[i][j];
    }

    return *this;
  }
  Matrix2d<T>& operator+=(const Matrix2d<T>& m) {
    return *this = *this + m;
  }
  Matrix2d<T>& operator-=(const Matrix2d<T>& m) {
    return *this = *this - m;
  }
  Matrix2d<T>& operator*=(const Matrix2d<T>& m) {
    return *this = *this * m;
  }
  // TODO(munseong): need to implement it when it's needed
  // Matrix2d<T>& operator/=(const Matrix2d<T>& m)
};

Matrix2d<int64_t> MatPow(Matrix2d<int64_t> m, int64_t p) {
  Matrix2d<int64_t> res(m.GetSize());
  for (; p; p >>= 1) {
    if (p & 1)
      res *= m;
    m *= m;
  }

  return res;
}

/*
 * odd  => A^n + s(n/2)(A^n/2 + I)
 * even => s(n/2)(A^n/2 + I)
 */
Matrix2d<int64_t> Rec(const Matrix2d<int64_t>& m, int64_t n) {
  static Matrix2d<int64_t> i(m.GetSize());
  if (n == 1)
    return m;

  auto res = Rec(m, n >> 1) * (MatPow(m, n >> 1) + i);
  if (n & 1)
    res += MatPow(m, n);

  return res;
}

int main() {
  CP;

  int n;
  std::cin >> n;
  int64_t b;
  std::cin >> b;
  Matrix2d<int64_t> m(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      std::cin >> m[i][j];
  }

  auto res = Rec(m, b);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      std::cout << res[i][j] % 1000 << ' ';
    std::cout << '\n';
  }

  return 0;
}
