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
  std::string str;
  std::getline(std::cin, str);
  std::stack<char> s;
  bool is_on = false;
  for (const char& c : str) {
    if (c == '<') {
      is_on = true;
      while (!s.empty()) {
        std::cout << s.top();
        s.pop();
      }
      std::cout << c;
    } else if (is_on) {
      std::cout << c;
      if (c == '>')
        is_on = false;
    } else if (c == ' ') {
      while (!s.empty()) {
        std::cout << s.top();
        s.pop();
      }
      std::cout << c;
    } else {
      s.push(c);
    }
  }
  while (!s.empty()) {
    std::cout << s.top();
    s.pop();
  }

  return 0;
}
