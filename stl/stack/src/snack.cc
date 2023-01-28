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

int main() {
  CP;

  int n;
  std::cin >> n;
  std::stack<int> s;
  int next = 1;
  while (n--) {
    int temp;
    std::cin >> temp;
    s.push(temp);
    while (!s.empty() && s.top() == next) {
      ++next;
      s.pop();
    }
  }
  std::cout << ((s.empty()) ? "Nice" : "Sad");

  return 0;
}
