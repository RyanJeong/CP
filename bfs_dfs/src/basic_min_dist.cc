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

  int r, c;
  std::cin >> r >> c;
  std::vector<std::vector<int>> v(r + 1, std::vector<int>(c + 1));
  std::vector<std::vector<bool>> is_visited(r + 1, std::vector<bool>(c + 1));
  std::queue<std::pair<int, int>> q;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      int temp;
      std::cin >> temp;
      if (temp == 2) {
        q.push({i, j});
        is_visited[i][j] = true;
      } else if (!temp) {
        is_visited[i][j] = true;
      } else {
        v[i][j] = -1;
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
      int y = cur.first + d.first;
      int x = cur.second + d.second;

      if (y < 1 || y > r)
        continue;
      if (x < 1 || x > c)
        continue;
      if (is_visited[y][x])
        continue;
      q.push({y, x});
      is_visited[y][x] = true;
      v[y][x] = v[cur.first][cur.second] + 1;
    }
  }

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cout << v[i][j] << ' ';
    std::cout << '\n';
  }

  return 0;
}
