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

// deque
using std::deque;

int main() {
  CP;

  std::deque<int> dq;
  dq.push_back(10);   // { 10 }
  dq.push_back(40);   // { 10 40 }
  dq.push_front(50);  // { 50 10 40 }
  std::cout << dq.size() << '\n';   // 3
  std::cout << dq.front() << '\n';  // 50
  std::cout << dq.back() << '\n';   // 40
  if (dq.empty())
    std::cout << "deque is empty!\n";
  else
    std::cout << "Deque is not empty!\n";  // print "Deque is not empty!"

  dq.pop_front();    // { 10 40 }
  dq.push_back(60);  // { 10 40 60 }
  dq.pop_back();     // { 10 40 }
  std::cout << dq.front() << '\n';  // 10
  std::cout << dq.back() << '\n';   // 40
  for (const int& i : dq)
    std::cout << i << ' ';  // 10 40
  std::cout << '\n';

  return 0;
}
