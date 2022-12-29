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

  int m, n;
  std::cin >> m >> n;
  std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));
  std::vector<std::vector<bool>> is_visited(n + 1, std::vector<bool>(m + 1));
  std::queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> v[i][j];
      if (v[i][j] == 1) {
        --v[i][j];
        q.push({i, j});
        is_visited[i][j] = true;
      } else if (v[i][j] == -1) {
        is_visited[i][j] = true;
      }
    }
  }

  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    // horizontally, vertically
    const std::vector<std::pair<int, int>> kAdj = {
      {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (const auto& d : kAdj) {
      int x = cur.first + d.first;
      int y = cur.second + d.second;

      if (x < 1 || x > n)
        continue;
      if (y < 1 || y > m)
        continue;
      if (is_visited[x][y])
        continue;
      q.push({x, y});
      is_visited[x][y] = true;
      v[x][y] = v[cur.first][cur.second] + 1;
    }
  }

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (!is_visited[i][j]) {
        std::cout << -1;

        return 0;
      }
      res = std::max(res, v[i][j]);
    }
  }
  std::cout << res;

  return 0;
}
