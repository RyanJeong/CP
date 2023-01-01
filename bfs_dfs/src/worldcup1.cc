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
#include <cstring>

bool dfs(int round);

std::vector<std::pair<int, int>> matches;
int arr[6][3];
int buf[6][3];

int main() {
  CP;

  // 6 Comb. 2
  for (int i = 0; i < 6; ++i) {
    for (int j = i + 1; j < 6; ++j)
      matches.push_back({i, j});
  }

  for (int t = 0; t < 4; ++t) {
    memset(buf, 0, sizeof buf);

    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j)
        std::cin >> arr[i][j];
    }
    std::cout << dfs(0) << ' ';
  }

  return 0;
}

bool dfs(int round) {
  if (round == matches.size()) {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (arr[i][j] == buf[i][j])
          continue;

        return false;
      }
    }

    return true;
  }

  const int& t1 = matches[round].first;
  const int& t2 = matches[round].second;
  const std::vector<std::pair<int, int>> kCases = {
    {0, 2}, {1, 1}, {2, 0}};  // {w, l}, {d, d}, {l, w}
  for (const auto& c : kCases) {
    const int& res1 = c.first;
    const int& res2 = c.second;

    ++buf[t1][res1];
    ++buf[t2][res2];
    if (dfs(round + 1))
      return true;
    --buf[t1][res1];
    --buf[t2][res2];
  }

  return false;
}
