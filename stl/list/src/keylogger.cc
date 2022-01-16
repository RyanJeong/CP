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

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// list
using std::list;

int main() {
  CP;

  int l;
  cin >> l;
  while (l--) {
    string s;
    cin >> s;
    list<char> l;
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
      cout << c;
    cout << '\n';
  }

  return 0;
}
