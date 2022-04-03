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
#include <stack>

// iostream
using std::cin;
using std::cout;

// string
using std::string;
using std::getline;

// stack
using std::stack;

int main() {
  string str;
  getline(cin, str);
  stack<char> s;
  bool is_on = false;
  for (const char& c : str) {
    if (c == '<') {
      is_on = true;
      while (!s.empty()) {
        cout << s.top();
        s.pop();
      }
      cout << c;
    } else if (is_on) {
      cout << c;
      if (c == '>')
        is_on = false;
    } else if (c == ' ') {
      while (!s.empty()) {
        cout << s.top();
        s.pop();
      }
      cout << c;
    } else {
      s.push(c);
    }
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }

  return 0;
}
