#include <vector>

using std::vector;

// if you want to get sorted result, you should sort() after divisors()
template <typename T1, typename T2>
void divisors(T1 n, vector<T2>* v) {
  for (T1 i = 1; i * i <= n; ++i) {
    if (n % i)
      continue;
    v->push_back(i);
    if (n / i != i)
      v->push_back(n / i);
  }
}
