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

  string str;
  cin >> str;
  bool is_valid = true;
  stack<char> s;
  int value = 1;
  int total_value = 0;
  char prev;
  for (const char& c : str) {
    if (c == '(' || c == '[') {
      s.push(c);
      value *= ((c == '(') ? 2 : 3);
    } else if (!s.empty() && s.top() == '(' && c == ')') {
      if (prev == '(')
        total_value += value;
      s.pop();
      value /= 2;
    } else if (!s.empty() && s.top() == '[' && c == ']') {
      if (prev == '[')
        total_value += value;
      s.pop();
      value /= 3;
    } else {
      is_valid = false;
      break;
    }
    prev = c;
  }
  cout << ((!s.empty() || !is_valid) ? 0 : total_value);

  return 0;
}
