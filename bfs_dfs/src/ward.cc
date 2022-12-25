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
#include <string>
#include <queue>
#include <utility>

int main() {
  CP;

  int r, c;
  std::cin >> r >> c;
  std::vector<std::vector<char>> v(r + 1, std::vector<char>(c + 1));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cin >> v[i][j];
  }

  int hr, hc;
  std::cin >> hr >> hc;
  std::string path;
  std::cin >> path;
  std::vector<std::vector<bool>> is_visited(r + 1, std::vector<bool>(c + 1));
  std::queue<std::pair<int, int>> q;
  for (const char& c : path) {
    switch (c) {
      case 'U':
        --hr;
        break;
      case 'D':
        ++hr;
        break;
      case 'L':
        --hc;
        break;
      case 'R':
        ++hc;
        break;
      case 'W':
        q.push({hr, hc});
        is_visited[hr][hc] = true;
        break;
    }
  }

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
      if (is_visited[y][x] || v[y][x] != v[cur.first][cur.second])
        continue;
      q.push({y, x});
      is_visited[y][x] = true;
    }
  }
  is_visited[hr][hc] = true;
  if (hr - 1 >= 1)
    is_visited[hr-1][hc] = true;
  if (hc - 1 >= 1)
    is_visited[hr][hc-1] = true;
  if (hr + 1 <= r)
    is_visited[hr+1][hc] = true;
  if (hc + 1 <= c)
    is_visited[hr][hc+1] = true;

  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cout << (is_visited[i][j] ? '.' : '#');
    std::cout << '\n';
  }

  return 0;
}
