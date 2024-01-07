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

template <typename T>
std::vector<int> GetFail(const T& pattern);

int main() {
  CP;

  std::string str;
  std::cin >> str;
  auto fail = GetFail(str);
  std::string res;
  int len = fail[str.length()-1];  // postfix's length
  while (len > 0) {
    // skip prefix's first character and postfix's last character
    for (int i = 1; i < str.length() - 1; ++i) {
      if (fail[i] != len)
        continue;
      res = str.substr(0, len);
      break;
    }
    if (!res.empty())
      break;
    len = fail[len-1];
  }
  std::cout << ((res.empty()) ? "-1" : res);

  return 0;
}

template <typename T>
std::vector<int> GetFail(const T& p) {
  std::vector<int> fail(p.size());
  int j = 0;
  for (int i = 1; i < p.size(); i++) {
    while (j > 0 && p[i] != p[j])
      j = fail[j-1];  // restore the idx
    if (p[i] == p[j])
      fail[i] = ++j;  // after j
  }

  return fail;
}
