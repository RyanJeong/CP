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
#include <queue>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::queue<int> q;
  while (n--) {
    std::string str;
    std::cin >> str;

    if (str == "push") {
      int v;
      std::cin >> v;
      q.push(v);
    } else if (str == "pop") {
      if (q.empty()) {
        std::cout << -1 << '\n';
      } else {
        std::cout << q.front() << '\n';
        q.pop();
      }
    } else if (str == "size") {
      std::cout << q.size() << '\n';
    } else if (str == "empty") {
      std::cout << q.empty() << '\n';
    } else if (str == "front") {
      std::cout << ((q.empty()) ? -1 : q.front()) << '\n';
    } else if (str == "back") {
      std::cout << ((q.empty()) ? -1 : q.back()) << '\n';
    }
  }

  return 0;
}
