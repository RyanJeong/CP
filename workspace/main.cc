/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using std::cin;
using std::cout;

using std::vector;

using std::sqrt;

using std::lower_bound;

template<typename T>
vector<int> eratosthenes_sieve(T from, T to) {
  static vector<bool> is_composition(to + 1);  // 1-based
  vector<int> primes;

  if (from < 2)  // 1 is not a prime number
    from = 2;
  for (T i = 2; i * i <= to; ++i) {
    if (is_composition[i])
      continue;
    for (T j = i * i; j <= to; j += i)
      is_composition[j] = true;
  }
  for (T i = from; i <= to; ++i) {
    if (!is_composition[i])
      primes.push_back(i);
  }

  return primes;
}

int main() {
  CP;

  int from = 0;
  int to = static_cast<int>(sqrt(4e9));
  vector<int> primes = eratosthenes_sieve(from, to);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t n;
    cin >> n;
    auto it = lower_bound(primes.begin(), primes.end(), n);
    cout << *it << '\n';
  }

  return 0;
}
