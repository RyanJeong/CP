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

  std::stack<int> s;
  s.push(10);  // { 10 }
  s.push(20);  // { 10 20 }
  s.push(30);  // { 10 20 30 }
  std::cout << s.size() << '\n';  // 3
  if (s.empty())
    std::cout << "stack is empty!\n";
  else
    std::cout << "stack is not empty!\n";  // stack is not empty!
  std::cout << s.top() << '\n';  // 30
  s.pop();  // { 10 20 }, return value is none!
  std::cout << s.top() << '\n';  // 20
  s.pop();  // { 10 }
  s.pop();  // (empty)
  if (s.empty())
    std::cout << "stack is empty!\n";  // stack is empty!
  else
    std::cout << "stack is not empty!\n";

  return 0;
}
