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

  int n, m;
  std::cin >> n >> m;

  std::map<std::string, std::string> pw_of;
  while (n--) {
    std::string site, pw;
    std::cin >> site >> pw;
    pw_of[site] = pw;
  }

  while (m--) {
    std::string site;
    std::cin >> site;
    std::cout << pw_of[site] << '\n';
  }

  return 0;
}
