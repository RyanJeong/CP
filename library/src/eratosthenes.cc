#include <vector>

using std::vector;

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
