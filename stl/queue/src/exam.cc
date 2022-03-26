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

// iostream
using std::cin;
using std::cout;

// queue
using std::queue;

int main() {
  CP;

  queue<int> q;

  q.push(10);                // { 10 }
  q.push(20);                // { 10 20 }
  q.push(30);                // { 10 20 30 }
  cout << q.size() << '\n';  // 3
  if (q.empty())
    cout << "Queue is empty!\n";
  else
    cout << "Queue is not empty!\n";  // print "Queue is not empty!"
  cout << q.front() << '\n';  // 10
  cout << q.back() << '\n';   // 30
  q.pop();                    // { 20 30 }
  q.push(40);                 // { 20 30 40 }
  cout << q.front() << '\n';  // 20
  cout << q.back() << '\n';   // 40

  return 0;
}

