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
#include <functional>

int main() {
  CP;

  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> v(n + 1, std::vector<int>(n + 1));
  std::priority_queue<std::pair<int, std::pair<int, int>>,
                      std::vector<std::pair<int, std::pair<int, int>>>,
                      std::greater<std::pair<int, std::pair<int, int>>>> temp;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> v[i][j];
      if (!v[i][j])
        continue;
      temp.push({v[i][j], {i, j}});
    }
  }
  int s, r, c;
  std::cin >> s >> r >> c;

  std::queue<std::pair<int, int>> q;
  std::vector<std::vector<bool>> is_visited(n + 1, std::vector<bool>(n + 1));
  while (!temp.empty()) {
    auto cur = temp.top().second;
    temp.pop();

    q.push({cur.first, cur.second});
    is_visited[cur.first][cur.second] = true;
  }

  while (s--) {
    for (int size = q.size(); size; --size) {
      auto cur = q.front();
      q.pop();

      // horizontally, vertically
      const std::vector<std::pair<int, int>> kAdj = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      for (const auto& d : kAdj) {
        int y = cur.first + d.first;
        int x = cur.second + d.second;

        if (y < 1 || y > n)
          continue;
        if (x < 1 || x > n)
          continue;
        if (is_visited[y][x] || v[y][x])
          continue;
        v[y][x] = v[cur.first][cur.second];
        q.push({y, x});
        is_visited[y][x] = true;
      }
    }
  }
  std::cout << v[r][c];

  return 0;
}
