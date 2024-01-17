/*
  Copyright 2024 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP                            \
  do {                                \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
  } while (0)

#include <cmath>
#include <iostream>
#include <vector>

int main() {
  CP;

  int max = std::sqrt(4 * 10e9);
  std::vector<bool> composition(max + 1);
  int cnt = 0;
  for (int i = 2; i * i <= max; ++i) {
    if (composition[i]) continue;
    for (int j = i * i; j <= max; j += i) {
      composition[j] = true;
      ++cnt;
    }
  }

  std::vector<int> prime;
  prime.reserve(cnt);
  for (int i = 2; i <= max; ++i) {
    if (!composition[i]) prime.push_back(i);
  }

  int n;
  std::cin >> n;
  std::cout << prime[n - 1];
  return 0;
}
