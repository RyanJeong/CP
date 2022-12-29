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
#include <set>

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
  std::vector<std::vector<int>> buf(n + 1, std::vector<int>(m + 1, -1));
  std::vector<int> areas;
  int area_idx = 0;
  std::queue<std::pair<int, int>> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (is_visited[i][j] || v[i][j] == '1')
        continue;

      q.push({i, j});
      is_visited[i][j] = true;
      buf[i][j] = area_idx;
      int area_size = 0;
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        ++area_size;
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
          if (is_visited[x][y] || v[x][y] == '1')
            continue;
          q.push({x, y});
          is_visited[x][y] = true;
          buf[x][y] = area_idx;
        }
      }
      areas.push_back(area_size);
      ++area_idx;
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (v[i][j] == '0')
        continue;

      std::set<int> s;  // remove dup. cases

      // horizontally, vertically
      const std::vector<std::pair<int, int>> kAdj = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      for (auto d : kAdj) {
        int x = i + d.first;
        int y = j + d.second;

        if (x < 1 || x > n)
          continue;
        if (y < 1 || y > m)
          continue;
        if (buf[x][y] == -1)
          continue;
        s.insert(buf[x][y]);
      }
      int cnt = 1;
      for (const int& idx : s)
        cnt += areas[idx];
      cnt %= 10;
      v[i][j] = cnt + '0';
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      std::cout << v[i][j];
    std::cout << '\n';
  }

  return 0;
}
