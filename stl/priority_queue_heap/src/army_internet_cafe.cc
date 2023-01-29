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
#include <set>

int main() {
  CP;

  int n;
  std::cin >> n;
  // <from,to>
  std::vector<std::pair<int, int>> v;
  for (int i = 0; i < n; ++i) {
    int s, t;
    std::cin >> s >> t;
    v.push_back({s, t});
  }
  std::sort(v.begin(), v.end());

  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> pq;
  std::set<int> s;
  std::vector<int> freq;
  for (int i = 0; i < n; ++i) {
    while (!pq.empty()) {
      if (pq.top().first > v[i].first)
        break;

      s.insert(pq.top().second);
      pq.pop();
    }
    if (s.empty()) {
      pq.push({v[i].second, freq.size()});
      freq.push_back(1);
    } else {
      auto cur = s.begin();
      pq.push({v[i].second, *cur});
      ++freq[*cur];
      s.erase(cur);
    }
  }
  std::cout << freq.size() << '\n';
  for (const int& i : freq)
    std::cout << i << ' ';

  return 0;
}
