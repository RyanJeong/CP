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

// iostream
using std::cin;
using std::cout;

// stack;
using std::stack;

int main() {
  CP;

  stack<int> s;
  s.push(10);  // { 10 }
  s.push(20);  // { 10 20 }
  s.push(30);  // { 10 20 30 }
  cout << s.size() << '\n';  // 3
  if (s.empty())
    cout << "Stack is empty!\n";
  else
    cout << "Stack is not empty!\n";  // print "Stack is not empty!"
  cout << s.top() << '\n';  // 30
  s.pop();  // { 10 20 }, return value is none!
  cout << s.top() << '\n';  // 20
  s.pop();  // { 10 }
  s.pop();  // (empty)
  if (s.empty())
    cout << "Stack is empty!\n";  // print "Stack is empty!"
  else
    cout << "Stack is not empty!\n";

  return 0;
}
