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
#include <algorithm>
#include <map>

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// algorithm
using std::reverse;

// map
using std::map;

int main() {
  CP;

  int t;
  cin >> t;
  map<string, bool> m;
  while (t--) {
    string str;
    cin >> str;
    string rev_str = str;
    reverse(rev_str.begin(), rev_str.end());
    if (str == rev_str || m.find(rev_str) != m.end()) {
      cout << str.length() << ' ' << str[str.length() / 2] << '\n';
      break;
    } else {
      m[str] = true;
    }
  }

  return 0;
}
