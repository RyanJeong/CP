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
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// queue
using std::queue;

// utility
using std::pair;

// algorithm
using std::sort;

// functional
using std::greater;

int solution(const vector<int>&, int);

int main() {
  CP;

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& i : v)
      cin >> i;
    int l;
    cin >> l;
    cout << solution(v, l) << '\n';
  }

  return 0;
}

int solution(const vector<int>& priorities, int location) {
  queue<pair<int, int>> q;  // priority, index;
  vector<int> v;  // priority
  for (int i = 0; i < priorities.size(); ++i) {
    q.push({priorities[i], i});
    v.push_back(priorities[i]);
  }
  sort(v.begin(), v.end(), greater<int>());

  int res = 0;
  for (int& i : v) {
    while (i != q.front().first) {
      auto cur = q.front();
      q.pop();
      q.push(cur);
    }
    ++res;
    if (location == q.front().second)
      break;
    q.pop();
  }

  return res;
}

