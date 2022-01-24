/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <stack>
#include <string>

// iostream
using std::cin;
using std::cout;

// stack;
using std::stack;

// string
using std::string;

int main() {
  CP;

  int n;
  cin >> n;
  stack<int> s;
  while (n--) {
    string str;
    cin >> str;
    if (str == "push") {
      int v;
      cin >> v;
      s.push(v);
    } else if (str == "pop") {
      if (s.empty()) {
        cout << -1 << '\n';
      } else {
        cout << s.top() << '\n';
        s.pop();
      }
    } else if (str == "size") {
      cout << s.size() << '\n';
    } else if (str == "empty") {
      cout << s.empty() << '\n';
    } else if (str == "top") {
      cout << ((s.empty()) ? -1 : s.top()) << '\n';
    }
  }

  return 0;
}
