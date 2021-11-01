/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/
#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0 && (n - i) % 3 == 0) {
      std::cout << ',';
    }
    std::cout << s[i];
  }

  return 0;
}
