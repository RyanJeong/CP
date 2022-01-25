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

  int n;
  cin >> n;
  stack<int> s;
  int next = 1;
  while (n--) {
    int temp;
    cin >> temp;
    s.push(temp);
    while (!s.empty() && s.top() == next) {
      ++next;
      s.pop();
    }
  }
  cout << ((s.empty()) ? "Nice" : "Sad");

  return 0;
}
