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

using std::cin;
using std::cout;

using std::vector;

int gcd(int, int);
int64_t lcm(int64_t, int);

int main() {
  CP;
  int a, b;
  cin >> a >> b;
  if (a == b) {
    cout << 1;

    return 0;
  }
  if (a < b) {
    int temp = a;
    a = b;
    b = temp;
  }
  // a > b:
  // gcd(a, b) == gcd(a - b, b)
  // gcd(a + n, b + n) == gcd(a - b, b + n)
  int diff = a - b;
  vector<int> v;
  for (int i = 1; i * i <= diff; ++i) {
    if (diff % i)
      continue;
    v.push_back(i);
    if (diff / i != i)
      v.push_back(diff / i);
  }
  int64_t min = 1e18;
  int res = diff;
  for (const int& i : v) {
    if (!(b % i))
      continue;
    int n = i - b % i;
    int64_t temp = lcm(a + n, b + n);
    if (min < temp)
      continue;
    if (min > temp)
      min = temp;
    res = n;
  }
  cout << res;

  return 0;
}

int gcd(int a, int b) {
  return (!b) ? a : gcd(b, a % b);
}

int64_t lcm(int64_t a, int b) {
  return a / gcd(a, b) * b;  // escape overflow
}
