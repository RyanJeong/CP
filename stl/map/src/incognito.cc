/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <string>
#include <map>

int main() {
  CP;

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::map<std::string, int> m;
    for (int i = 0; i < n; ++i) {
      std::string val, key;
      std::cin >> val >> key;
      if (m.find(key) == m.end())
        m[key] = 1;
      else
        ++m[key];
    }
    int mul = 1;
    // {3 2 1 0} x {2 1 0} - n(0)
    for (const auto& i : m)
      mul *= i.second + 1;
    std::cout << mul - 1 << '\n';
  }

  return 0;
}
