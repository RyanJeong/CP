/*
  Copyright 2024 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP                            \
  do {                                \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(NULL);               \
  } while (0)

#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  CP;

  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    std::unordered_set<std::string> s;
    for (std::string str; a--; s.insert(str)) std::cin >> str;
    for (std::string str; b--; s.insert(str)) std::cin >> str;
    for (;;) {}
    std::cout << s.size() << '\n';
  }
  return 0;
}
