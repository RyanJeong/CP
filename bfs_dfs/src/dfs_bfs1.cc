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
#include <stack>
#include <queue>
#include <utility>

void dfs(int n, int v);
void bfs(int n, int v);

std::vector<std::vector<int>> g;
std::vector<bool> is_visited;

int main() {
  CP;

  int n, m, v;
  std::cin >> n >> m >> v;
  g = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1));
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }

  dfs(n, v);
  std::cout << '\n';
  bfs(n, v);

  return 0;
}

void dfs(int n, int v) {
  std::stack<int> s;
  s.push(v);
  is_visited = std::vector<bool>(n + 1);
  while (!s.empty()) {
    auto cur = s.top();
    s.pop();

    if (is_visited[cur])
      continue;
    is_visited[cur] = true;
    std::cout << cur << ' ';
    // NOTICE: Search in reverse order considering the characteristics of the
    //         stack
    for (int i = n; i > 0; --i) {
      if (is_visited[i])
        continue;
      if (!g[cur][i])
        continue;
      s.push(i);
    }
  }

  return;
}

void bfs(int n, int v) {
  std::queue<int> q;
  q.push(v);
  is_visited = std::vector<bool>(n + 1);
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
