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
  std::vector<std::vector<bool>> is_visited(n + 1, std::vector<bool>(m + 1));
  int goats = 0;
  int wolves = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (is_visited[i][j] || v[i][j] == '#')
        continue;

      int goat = 0;
      int wolf = 0;
      if (v[i][j] == 'v')
        ++wolf;
      if (v[i][j] == 'k')
        ++goat;
      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      is_visited[i][j] = true;
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
          if (is_visited[x][y] || v[x][y] == '#')
            continue;
          if (v[x][y] == 'v')
            ++wolf;
          if (v[x][y] == 'k')
            ++goat;
          q.push({x, y});
          is_visited[x][y] = true;
        }
      }
      if (goat > wolf)
        goats += goat;
      else
        wolves += wolf;
    }
  }
  std::cout << goats << ' ' << wolves;

  return 0;
}
