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
#include <algorithm>

int bt(int i, int j);

std::vector<std::vector<char>> v;
std::vector<bool> is_visited;
int r, c;

int main() {
  CP;

  std::cin >> r >> c;
  v = std::vector<std::vector<char>>(r + 1, std::vector<char>(c + 1));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cin >> v[i][j];
  }
  is_visited = std::vector<bool>('Z' - 'A' + 1);
  is_visited[v[1][1]-'A'] = true;
  std::cout << bt(1, 1);

  return 0;
}

int bt(int i, int j) {
  int movement = 1;

  // horizontally, vertically
  const std::vector<std::pair<int, int>> kAdj = {
    {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  for (const auto& d : kAdj) {
    int y = i + d.first;
    int x = j + d.second;

    if (y < 1 || y > r)
      continue;
    if (x < 1 || x > c)
      continue;
    if (is_visited[v[y][x]-'A'])
      continue;
    is_visited[v[y][x]-'A'] = true;
    movement = std::max(movement, bt(y, x) + 1);
    is_visited[v[y][x]-'A'] = false;
  }

  return movement;
}
