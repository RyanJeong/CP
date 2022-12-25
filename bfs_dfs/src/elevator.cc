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

  int f, s, g, u, d;
  std::cin >> f >> s >> g >> u >> d;
  std::vector<int> v(f + 1, -1);

  std::queue<int> q;
  q.push(s);
  v[s] = 0;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    const int dx[] = {u, -d};
    for (const int& d : dx) {
      int x = cur+d;

      if (x < 1 || x > f)
        continue;
      if (v[x] != -1)
        continue;
      q.push(x);
      v[x] = v[cur] + 1;
    }
  }
  if (v[g] == -1)
    std::cout << "use the stairs";
  else
    std::cout << v[g];

  return 0;
}
