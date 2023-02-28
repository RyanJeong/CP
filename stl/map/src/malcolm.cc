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
#include <string>
#include <map>
#include <algorithm>

int main() {
  CP;

  int n, k;
  std::cin >> n >> k;
  std::map<int, std::vector<int>> m;
  for (int i = 0; i < n; ++i) {
    std::string str;
    std::cin >> str;
    m[str.size()].push_back(i);
  }

  int64_t res = 0;
  for (const auto& i : m) {
    std::vector<int> v = i.second;
    for (int i = 0; i < v.size(); ++i) {
      auto curr = std::upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
      res += (curr - i - 1);
    }
  }
  std::cout << res;

  return 0;
}
