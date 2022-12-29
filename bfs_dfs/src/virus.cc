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

int dfs(int n, int v);

std::vector<std::vector<int>> g;
std::vector<bool> is_visited;

int main() {
  CP;

  int n, m;
  std::cin >> n >> m;
  g = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1));
  while (m--) {
    int i, j;
    std::cin >> i >> j;
    g[i][j] = g[j][i] = 1;
  }
  is_visited = std::vector<bool>(n + 1);
  std::cout << dfs(n, 1);

  return 0;
}

int dfs(int n, int v) {
  static int cnt = 0;

  is_visited[v] = true;
  for (int i = 1; i <= n; ++i) {
    if (is_visited[i])
      continue;
    if (!g[v][i])
      continue;
    ++cnt;
    dfs(n, i);
  }

  return cnt;
}
