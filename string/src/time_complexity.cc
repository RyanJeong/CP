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

// iostream
using std::cin;
using std::cout;

// string
using std::string;

int main() {
  CP;

  int n;
  cin >> n;
  int res = 0;
  while (n--) {
    string str;
    cin >> str;
    int cnt = 0;
    int len = str.length();
    // for (int i = 0; i < str.length() - 2; ++i)
    // -> may occurred an overflow! (length()'s return type is size_t)
    for (int i = 0; i < len - 2; ++i) {
      if (str.substr(i, 3) == "for")
        ++cnt;
    }
    for (int i = 0; i < len - 4; ++i) {
      if (str.substr(i, 5) == "while")
        ++cnt;
    }
    if (res < cnt)
      res = cnt;
  }
  cout << res;

  return 0;
}
