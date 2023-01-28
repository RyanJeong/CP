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

int main() {
  CP;

  std::string str;
  while (std::getline(std::cin, str)) {
    if (str == ".")
      break;

    std::stack<char> bracket;
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
    std::cout << ((is_valid && bracket.empty()) ? "yes" : "no") << '\n';
  }

  return 0;
}
