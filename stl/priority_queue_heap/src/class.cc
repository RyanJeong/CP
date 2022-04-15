/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <functional>

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// utility
using std::pair;

// algorithm
using std::sort;

// queue
using std::priority_queue;

// functional
using std::greater;

int main() {
  CP;

  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (auto& i : v)
    cin >> i.first >> i.second;

  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  pq.push(-1);
  for (const auto& i : v) {
    auto& cur = pq.top();
    if (i.first >= cur)
      pq.pop();
    pq.push(i.second);
  }
  cout << pq.size();

  return 0;
}
