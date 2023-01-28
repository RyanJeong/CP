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

int main() {
  CP;

  int n;
  std::cin >> n;
  std::stack<int> s;
  while (n--) {
    std::string str;
    std::cin >> str;
    if (str == "push") {
      int v;
      std::cin >> v;
      s.push(v);
    } else if (str == "pop") {
      if (s.empty()) {
        std::cout << -1 << '\n';
      } else {
        std::cout << s.top() << '\n';
        s.pop();
      }
    } else if (str == "size") {
      std::cout << s.size() << '\n';
    } else if (str == "empty") {
      std::cout << s.empty() << '\n';
    } else if (str == "top") {
      std::cout << ((s.empty()) ? -1 : s.top()) << '\n';
    }
  }

  return 0;
}
