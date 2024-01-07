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

int main() {
  CP;

  int n, len;
  std::cin >> n >> len;
  std::string str;
  std::cin >> str;
  int res = 0;
  int cnt = 0;
  for (int i = 0; i < str.length() - 2; ++i) {
    if (str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') {
      ++cnt;
      if (cnt == n) {
        ++res;
        --cnt;
      }
      ++i;
    } else {
      cnt = 0;
    }
  }
  std::cout << res;

  return 0;
}
