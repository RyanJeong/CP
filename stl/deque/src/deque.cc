/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <deque>
#include <string>

int main() {
  CP;

  int n;
  std::cin >> n;
  std::deque<int> dq;
  while (n--) {
    std::string str;
    std::cin >> str;

    if (str == "push_back") {
      int v;
      std::cin >> v;
      dq.push_back(v);
    } else if (str == "push_front") {
      int v;
      std::cin >> v;
      dq.push_front(v);
    } else if (str == "pop_front") {
      if (dq.empty()) {
        std::cout << -1 << '\n';
      } else {
        std::cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (str == "pop_back") {
      if (dq.empty()) {
        std::cout << -1 << '\n';
      } else {
        std::cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (str == "size") {
      std::cout << dq.size() << '\n';
    } else if (str == "empty") {
      std::cout << dq.empty() << '\n';
    } else if (str == "front") {
      std::cout << ((dq.empty()) ? -1 : dq.front()) << '\n';
    } else if (str == "back") {
      std::cout << ((dq.empty()) ? -1 : dq.back()) << '\n';
    }
  }

  return 0;
}
