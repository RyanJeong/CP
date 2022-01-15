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
using std::getline;

// string
using std::string;

// list
using std::list;

int main() {
  CP;

  string s;
  cin >> s;
  list<char> l;
  for (const char& c : s)
    l.push_back(c);
  int cnt;
  cin >> cnt;
  cin.ignore();  // consume '\n'

  auto cur = l.end();
  while (cnt--) {
    string str;
    getline(cin, str);
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
    cout << c;

  return 0;
}
