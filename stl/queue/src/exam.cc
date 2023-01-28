/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <queue>

int main() {
  CP;

  std::queue<int> q;

  q.push(10);                // { 10 }
  q.push(20);                // { 10 20 }
  q.push(30);                // { 10 20 30 }
  std::cout << q.size() << '\n';  // 3
  if (q.empty())
    std::cout << "queue is empty!\n";
  else
    std::cout << "queue is not empty!\n";  // std::queue is not empty!
  std::cout << q.front() << '\n';  // 10
  std::cout << q.back() << '\n';   // 30
  q.pop();                    // { 20 30 }
  q.push(40);                 // { 20 30 40 }
  std::cout << q.front() << '\n';  // 20
  std::cout << q.back() << '\n';   // 40

  return 0;
}
