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
#include <vector>
#include <functional>

// iostream
using std::cin;
using std::cout;

// queue
using std::priority_queue;

// vector
using std::vector;

// functional
using std::greater;

int main() {
  CP;

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> min_heap;
  while (n--) {
    int x;
    cin >> x;
    if (x) {
      min_heap.push(x);
    } else {
      if (min_heap.empty()) {
        cout << '0';
      } else {
        cout << min_heap.top();
        min_heap.pop();
      }
      cout << '\n';
    }
  }

  return 0;
}
