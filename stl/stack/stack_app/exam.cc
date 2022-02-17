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

// stack;
using std::stack;

int main() {
  CP;

  int n;
  cin >> n;
  while (n--) {
    string ps;
    cin >> ps;
    bool is_vps = true;
    stack<int> s;
    for (const char& c : ps) {
      if (c == '(') {
        s.push(c);
      } else {
        if (s.empty()) {
          is_vps = false;
          break;
        } else {
          if (s.top() != '(') {
            is_vps = false;
            break;
          } else {
            s.pop();
          }
        }
      }
    }
    // 6
    // (())())               : NO
    // (((()())()            : NO
    // (()())((()))          : YES
    // ((()()(()))(((())))() : NO
    // ()()()()(()()())()    : YES
    // (()((())()(           : NO
    cout << ((s.empty() && is_vps) ? "YES" : "NO") << '\n';
  }

  return 0;
}
