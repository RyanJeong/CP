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

void dfs(int, int, const std::vector<std::vector<int>>& g);
void bfs(int, int, const std::vector<std::vector<int>>& g);

int main() {
  CP;

  int n, m, v;
  std::cin >> n >> m >> v;
  std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1));
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }

  dfs(n, v, g);
  std::cout << '\n';
  bfs(n, v, g);

  return 0;
}

void dfs(int n, int v, const std::vector<std::vector<int>>& g) {
  static std::vector<bool> is_visited(n + 1);
  is_visited[v] = true;
  std::cout << v << ' ';
  for (int i = 1; i <= n; ++i) {
    if (is_visited[i])
      continue;
    if (!g[v][i])
      continue;
    dfs(n, i, g);
  }

  return;
}

void bfs(int n, int v, const std::vector<std::vector<int>>& g) {
  std::queue<int> q;
  q.push(v);
  std::vector<bool> is_visited(n + 1);
  is_visited[v] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    std::cout << cur << ' ';
    for (int i = 1; i <= n; ++i) {
      if (is_visited[i])
        continue;
      if (!g[cur][i])
        continue;
      q.push(i);
      is_visited[i] = true;
    }
  }

  return;
}
