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

  std::string s, t;
  std::cin >> s >> t;
  std::string res;
  for (const char& c : s) {
    res.push_back(c);
    if (c != t.back())
      continue;
    if (res.size() < t.size())
      continue;

    bool is_same = true;
    for (int i = 1; i <= t.size(); ++i) {
      if (res[res.size()-i] != t[t.size()-i]) {
        is_same = false;
        break;
      }
    }
    if (is_same) {
      for (int i = 0; i < t.size(); ++i)
        res.pop_back();
    }
  }
  std::cout << ((res.empty()) ? "FRULA" : res);

  return 0;
}
