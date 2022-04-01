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
using std::priority_queue;

int main() {
  CP;

  int n;
  cin >> n;
  priority_queue<int> max_heap;
  while (n--) {
    int x;
    cin >> x;
    if (x) {
      max_heap.push(x);
    } else {
      if (max_heap.empty()) {
        cout << '0';
      } else {
        cout << max_heap.top();
        max_heap.pop();
      }
      cout << '\n';
    }
  }

  return 0;
}
