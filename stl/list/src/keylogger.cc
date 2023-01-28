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
#include <list>

int main() {
  CP;

  int l;
  std::cin >> l;
  while (l--) {
    std::string s;
    std::cin >> s;
    std::list<char> l;
    auto cur = l.begin();
    for (const char& c : s) {
      switch (c) {
        case '-':
          if (cur != l.begin())
            cur = l.erase(prev(cur));
          break;
        case '<':
          if (cur != l.begin())
            --cur;
          break;
        case '>':
          if (cur != l.end())
            ++cur;
          break;
        default:
          l.insert(cur, c);
          break;
      }
    }
    for (const char& c : l)
      std::cout << c;
    std::cout << '\n';
  }

  return 0;
}
