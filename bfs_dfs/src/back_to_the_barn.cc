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

int Bt(int i, int j, int cnt);

std::vector<std::vector<char>> v;
std::vector<std::vector<bool>> is_visited;
int r, c, k;

int main() {
  CP;

  std::cin >> r >> c >> k;
  v = std::vector<std::vector<char>>(r + 1, std::vector<char>(c + 1));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cin >> v[i][j];
  }
  is_visited = std::vector<std::vector<bool>>(r + 1, std::vector<bool>(c + 1));
  is_visited[r][1] = true;
  std::cout << Bt(r, 1, 1);

  return 0;
}

int Bt(int i, int j, int cnt) {
  static int result = 0;

  if (i == 1 && j == c) {
    if (cnt == k)
      ++result;

    return result;
  }

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
    if (is_visited[y][x] || v[y][x] == 'T')
      continue;
    is_visited[y][x] = true;
    Bt(y, x, cnt + 1);
    is_visited[y][x] = false;
  }

  return result;
}
