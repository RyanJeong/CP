/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

#include <vector>

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
