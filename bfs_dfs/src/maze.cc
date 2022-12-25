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

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> v(n + 1, std::vector<char>(m + 1));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      std::cin >> v[i][j];
  }

  std::queue<std::pair<int, int>> q;
  q.push({1, 1});
  std::vector<std::vector<int>> dist(n + 1, std::vector<int>(m + 1));
  dist[1][1] = 1;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    // horizontally, vertically
    const std::vector<std::pair<int, int>> kAdj = {
      {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    for (auto d : kAdj) {
      int x = cur.first + d.first;
      int y = cur.second + d.second;

      if (x < 1 || x > n)
        continue;
      if (y < 1 || y > m)
        continue;

      // the std::vector `dist` can calculate distance
      // and check visit status at the same time
      if (dist[x][y] || v[x][y] == '0')
        continue;
      dist[x][y] = dist[cur.first][cur.second] + 1;
      q.push({x, y});
    }
  }
  std::cout << dist[n][m];

  return 0;
}
