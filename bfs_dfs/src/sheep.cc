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

  int t;
  std::cin >> t;
  while (t--) {
    int r, c;
    std::cin >> r >> c;
    std::vector<std::vector<char>> v(r + 1, std::vector<char>(c + 1));
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j)
        std::cin >> v[i][j];
    }

    std::vector<std::vector<bool>> is_visited(r + 1, std::vector<bool>(c + 1));
    int res = 0;
    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        if (v[i][j] == '.' || is_visited[i][j])
          continue;

        ++res;
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        is_visited[i][j] = true;
        while (!q.empty()) {
          auto cur = q.front();
          q.pop();

          // horizontally, vertically
          const std::vector<std::pair<int, int>> kAdj = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
          for (auto d : kAdj) {
            int y = cur.first + d.first;
            int x = cur.second + d.second;

            if (y < 1 || y > r)
              continue;
            if (x < 1 || x > c)
              continue;
            if (is_visited[y][x] || v[y][x] == '.')
              continue;
            q.push({y, x});
            is_visited[y][x] = true;
          }
        }
      }
    }
    std::cout << res << '\n';
  }

  return 0;
}
