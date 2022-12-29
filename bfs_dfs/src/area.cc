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

int main() {
  CP;

  int m, n, k;
  std::cin >> m >> n >> k;

  std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= k; ++i) {
    int x1, y1;
    std::cin >> x1 >> y1;
    ++x1;
    ++y1;
    int x2, y2;
    std::cin >> x2 >> y2;
    for (int x = x1; x <= x2; ++x) {
      for (int y = y1; y <= y2; ++y)
        v[x][y] = 1;
    }
  }

  std::vector<std::vector<bool>> is_visited(n + 1, std::vector<bool>(m + 1));
  std::vector<int> n_obj;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (is_visited[i][j] || v[i][j] == 1)
        continue;

      int area = 0;
      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      is_visited[i][j] = true;
      while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        ++area;

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
          if (is_visited[x][y] || v[x][y])
            continue;
          is_visited[x][y] = true;
          q.push({x, y});
        }
      }
      n_obj.push_back(area);
    }
  }
  std::sort(n_obj.begin(), n_obj.end());
  std::cout << n_obj.size() << '\n';
  for (const int& i : n_obj)
    std::cout << i << ' ';

  return 0;
}
