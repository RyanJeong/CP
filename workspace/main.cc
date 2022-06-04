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
#include <utility>

// iostream
using std::cin;
using std::cout;

// queue
using std::priority_queue;

// vector
using std::vector;

// functional
using std::less;

// functional
using std::pair;

int main() {
  CP;

  int n;
  cin >> n;
  priority_queue<
      pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> max_heap;
  while (n--) {
    int m;
    cin >> m;
    int max = 0;
    for (int i = 0; i < m; ++i) {
      int temp;
      cin >> temp;
      if (max < temp)
        max = temp;
    }
    max_heap.push({max, m});
  }

  auto curr = max_heap.top();
  max_heap.pop();
  int64_t res = 0;
  while (!max_heap.empty()) {
    auto temp = max_heap.top();
    max_heap.pop();
    res += static_cast<int64_t>(curr.first - temp.first) * temp.second;
  }
  cout << res;

  return 0;
}
