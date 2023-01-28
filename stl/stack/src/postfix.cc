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

int main() {
  CP;

  std::string str;
  std::cin >> str;
  std::stack<char> op;
  std::string res;
  for (const char& c : str) {
    if (std::isalpha(c) && std::isupper(c)) {
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
  std::cout << res;

  return 0;
}
