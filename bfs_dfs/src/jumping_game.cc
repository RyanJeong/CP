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

int main() {
  CP;

  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<char>> v(2 + 1, std::vector<char>(n + 1));
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= n; ++j)
      std::cin >> v[i][j];
  }

  std::queue<std::pair<int, int>> q;
  q.push({1, 1});
  std::vector<std::vector<bool>> is_visited(2 + 1, std::vector<bool>(n + 1));
  is_visited[1][1] = true;
  int time = 1;
  while (!q.empty()) {
    int cnt = q.size();
    while (cnt--) {
      auto cur = q.front();
      q.pop();

      const std::vector<std::pair<int, int>> jump_to = {
        {1, 1}, {1, -1}, {2, k}};
      for (auto d : jump_to) {
        int x = ((cur.first + d.first) & 1) + 1;  // 1->2, 2->1
        int y = cur.second + d.second;

        if (y > n) {
          std::cout << 1;

          return 0;
        }
        if (y < 1 || time >= y)
          continue;
        if (is_visited[x][y] || v[x][y] == '0')
          continue;
        q.push({x, y});
        is_visited[x][y] = true;
      }
    }
    ++time;
  }
  std::cout << 0;

  return 0;
}
