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

int solution(const std::vector<int>&, int);

int main() {
  CP;

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int& i : v)
      std::cin >> i;
    int l;
    std::cin >> l;
    std::cout << solution(v, l) << '\n';
  }

  return 0;
}

int solution(const std::vector<int>& priorities, int location) {
  std::queue<std::pair<int, int>> q;  // priority, index;
  std::vector<int> v;  // priority
  for (int i = 0; i < priorities.size(); ++i) {
    q.push({priorities[i], i});
    v.push_back(priorities[i]);
  }
  std::sort(v.begin(), v.end(), std::greater<int>());

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

