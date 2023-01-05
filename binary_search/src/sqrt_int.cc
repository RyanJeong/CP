/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>

int main() {
  CP;

  int64_t n;
  std::cin >> n;

  // sqrt(2^63-1) is 3037000499.98
  int64_t low, high, mid;
  low = 0;
  high = 3037000500;
  while (low < high) {
    mid = (low + high) / 2;
    if (n > mid * mid)
      low = mid + 1;
    else
      high = mid;
  }
  std::cout << low;

  return 0;
}
