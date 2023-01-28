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

  std::string s;
  std::cin >> s;
  std::list<char> l;
  for (const char& c : s)
    l.push_back(c);
  int cnt;
  std::cin >> cnt;
  std::cin.ignore();  // consume '\n'

  auto cur = l.end();
  while (cnt--) {
    std::string str;
    std::getline(std::cin, str);
    switch (str.front()) {
      case 'L':
        if (cur != l.begin())
          --cur;
        break;
      case 'D':
        if (cur != l.end())
          ++cur;
        break;
      case 'B':
        if (cur != l.begin())
          cur = l.erase(prev(cur));
        break;
      case 'P':
        l.insert(cur, str[2]);
        break;
    }
  }
  for (const char& c : l)
    std::cout << c;

  return 0;
}
