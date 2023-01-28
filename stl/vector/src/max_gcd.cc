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
#include <vector>
#include <cctype>
#include <algorithm>

int gcd(int, int);

int main() {
  CP;

  int n;
  std::cin >> n;
  std::cin.ignore();  // consume '\n'
  while (n--) {
    std::string str;
    std::getline(std::cin, str);
    int tmp = 0;
    std::vector<int> v;
    for (const char& c : str) {
      if (std::isdigit(c)) {
        tmp = tmp * 10 + (c - '0');
      } else {
        v.push_back(tmp);
        tmp = 0;
      }
    }
    v.push_back(tmp);

    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j)
        res = std::max(res, gcd(v[i], v[j]));
    }
    std::cout << res << '\n';
  }

  return 0;
}

int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}
