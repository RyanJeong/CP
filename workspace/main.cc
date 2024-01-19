/*
  Copyright 2024 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP                            \
  do {                                \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
  } while (0)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::vector<std::pair<int, std::string>> v(n);
  for (int i = 0; i < n; ++i) {
    std::string a;
    int b;
    std::cin >> a >> b;
    v[i] = {-b, a};
  }
  std::sort(v.begin(), v.end());
  std::cout << v.front().second;
  return 0;
}
