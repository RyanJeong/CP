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
#include <cctype>

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// stack;
using std::stack;

// cctype
using std::isalpha;
using std::isupper;

int main() {
  CP;

  string str;
  cin >> str;
  stack<char> op;
  string res;
  for (const char& c : str) {
    if (isalpha(c) && isupper(c)) {
      res += c;
      continue;
    }

    switch (c) {
      case '(':
        op.push(c);
        break;
      case '*':
      case '/':
        while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
          res += op.top();
          op.pop();
        }
        op.push(c);
        break;
      case '+':
      case '-':
        while (!op.empty() && op.top() != '(') {
          res += op.top();
          op.pop();
        }
        op.push(c);
        break;
      case ')':
        while (!op.empty() && op.top() != '(') {
          res += op.top();
          op.pop();
        }
        op.pop();
        break;
    }
  }
  while (!op.empty()) {
    res += op.top();
    op.pop();
  }
  cout << res;

  return 0;
}
