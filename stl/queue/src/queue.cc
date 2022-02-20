/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <string>
#include <queue>

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// queue
using std::queue;

int main() {
  CP;

  int n;
  cin >> n;
  queue<int> q;
  while (n--) {
    string str;
    cin >> str;

    if (str == "push") {
      int v;
      cin >> v;
      q.push(v);
    } else if (str == "pop") {
      if (q.empty()) {
        cout << -1 << '\n';
      } else {
        cout << q.front() << '\n';
        q.pop();
      }
    } else if (str == "size") {
      cout << q.size() << '\n';
    } else if (str == "empty") {
      cout << q.empty() << '\n';
    } else if (str == "front") {
      cout << ((q.empty()) ? -1 : q.front()) << '\n';
    } else if (str == "back") {
      cout << ((q.empty()) ? -1 : q.back()) << '\n';
    }
  }

  return 0;
}
