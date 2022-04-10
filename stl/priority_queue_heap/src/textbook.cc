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

  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<vector<int>> v(n + 1, vector<int>());
  vector<int> cnt_lock(n + 1);
  while (m--) {
    int s, t;
    cin >> s >> t;
    v[s].push_back(t);
    ++cnt_lock[t];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt_lock[i])
      continue;
    pq.push(i);
  }
  while (!pq.empty()) {
    auto curr = pq.top();
    pq.pop();
    cout << curr << ' ';
    for (const int& i : v[curr]) {
      --cnt_lock[i];
      if (cnt_lock[i])
        continue;
      pq.push(i);
    }
  }

  return 0;
}

