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

// iostream
using std::cin;
using std::cout;

// deque
using std::deque;

int main() {
  CP;

  deque<int> dq;
  dq.push_back(10);   // { 10 }
  dq.push_back(40);   // { 10 40 }
  dq.push_front(50);  // { 50 10 40 }
  cout << dq.size() << '\n';   // 3
  cout << dq.front() << '\n';  // 50
  cout << dq.back() << '\n';   // 40
  if (dq.empty())
    cout << "Deque is empty!\n";
  else
    cout << "Deque is not empty!\n";  // print "Deque is not empty!"

  dq.pop_front();    // { 10 40 }
  dq.push_back(60);  // { 10 40 60 }
  dq.pop_back();     // { 10 40 }
  cout << dq.front() << '\n';  // 10
  cout << dq.back() << '\n';   // 40
  for (const int& i : dq)
    cout << i << ' ';  // 10 40
  cout << '\n';

  return 0;
}
