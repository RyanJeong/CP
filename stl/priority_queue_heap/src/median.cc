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
using std::less;
using std::greater;

int main() {
  CP;

  int n;
  cin >> n;
  while (n--) {
    int m;
    cin >> m;
    cout << m / 2 + 1 << '\n';
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 1; i <= m; ++i) {
      int temp;
      cin >> temp;
      if (i & 1) {
        max_heap.push(temp);
        if (!min_heap.empty() && max_heap.top() > min_heap.top()) {
          min_heap.push(max_heap.top());
          max_heap.pop();
          max_heap.push(min_heap.top());
          min_heap.pop();
        }
        cout << max_heap.top() << ' ';
        if (max_heap.size() == 10)
          cout << '\n';
      } else {
        min_heap.push(temp);
      }
    }
    cout << '\n';
  }

  return 0;
}
