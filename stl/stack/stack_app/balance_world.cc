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
using std::getline;

// string
using std::string;

// stack;
using std::stack;

int main() {
  CP;

  string str;
  while (getline(cin, str)) {
    if (str == ".")
      break;

    stack<char> bracket;
    bool is_valid = true;
    for (const char& c : str) {
      if (c == '(' || c == '[') {
        bracket.push(c);
      } else if (c == ')') {
        if (bracket.empty() || bracket.top() != '(') {
          is_valid = false;
          break;
        }
        bracket.pop();
      } else if (c == ']') {
        if (bracket.empty() || bracket.top() != '[') {
          is_valid = false;
          break;
        }
        bracket.pop();
      }
    }
    cout << ((is_valid && bracket.empty()) ? "yes" : "no") << '\n';
  }

  return 0;
}
