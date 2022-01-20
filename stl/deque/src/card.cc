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
#include <deque>

// iostream
using std::cin;
using std::cout;

// stack
using std::stack;

// deque
using std::deque;

int main() {
  CP;

  int n;
  cin >> n;
  stack<int> s;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    s.push(a);
  }

  deque<int> dq;
  for (int card = 1; !s.empty(); ++card) {
    int op = s.top();
    s.pop();
    if (op == 1) {
      dq.push_front(card);
    } else if (op == 2) {
      int tmp = dq.front();
      dq.pop_front();
      dq.push_front(card);
      dq.push_front(tmp);
    } else if (op == 3) {
      dq.push_back(card);
    }
  }
  for (const int& i : dq) {
    cout << i << ' ';
  }

  return 0;
}
