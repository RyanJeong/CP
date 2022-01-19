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

// iostream
using std::cin;
using std::cout;

// deque
using std::deque;

// string
using std::string;

int main() {
  CP;

  int n;
  cin >> n;
  deque<int> dq;
  while (n--) {
    string str;
    cin >> str;

    if (str == "push_back") {
      int v;
      cin >> v;
      dq.push_back(v);
    } else if (str == "push_front") {
      int v;
      cin >> v;
      dq.push_front(v);
    } else if (str == "pop_front") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    } else if (str == "pop_back") {
      if (dq.empty()) {
        cout << -1 << '\n';
      } else {
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    } else if (str == "size") {
      cout << dq.size() << '\n';
    } else if (str == "empty") {
      cout << dq.empty() << '\n';
    } else if (str == "front") {
      cout << ((dq.empty()) ? -1 : dq.front()) << '\n';
    } else if (str == "back") {
      cout << ((dq.empty()) ? -1 : dq.back()) << '\n';
    }
  }

  return 0;
}
