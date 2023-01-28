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

  int n;
  std::cin >> n;
  while (n--) {
    std::string ps;
    std::cin >> ps;
    bool is_vps = true;
    std::stack<int> s;
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
    std::cout << ((s.empty() && is_vps) ? "YES" : "NO") << '\n';
  }

  return 0;
}
