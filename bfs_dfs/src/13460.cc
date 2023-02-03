/*
  Copyright 2023 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
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

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> v(n + 1, std::vector<char>(m + 1));
  int r_y, r_x, b_y, b_x;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> v[i][j];
      if (v[i][j] == 'R') {
        r_y = i;
        r_x = j;
        v[i][j] = '.';
      }
      if (v[i][j] == 'B') {
        b_y = i;
        b_x = j;
        v[i][j] = '.';
      }
    }
  }

  // { RED_POS, BLACK_POS }
  std::queue<std::pair<std::pair<int, int>, std::pair<int, int>>> q;
  q.push({{r_y, r_x}, {b_y, b_x}});
  std::vector<std::vector<std::vector<std::vector<bool>>>> is_visited(
      n + 1, std::vector<std::vector<std::vector<bool>>>(
          m + 1, std::vector<std::vector<bool>>(
              n + 1, std::vector<bool>(m + 1))));
  is_visited[r_y][r_x][b_y][b_x] = true;

  int time = 1;
  bool is_possible = false;
  while (!q.empty()) {
    int cnt = q.size();
    while (cnt--) {
      auto curr = q.front();
      q.pop();

      // horizontally, vertically
      const std::vector<std::pair<int, int>> kAdj = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
      for (const auto& d : kAdj) {
        int black_y = curr.second.first;
        int black_x = curr.second.second;
        int black_cnt = 0;
        // to make a complex expression more readable.
        while (v[black_y][black_x] != 'O' &&
               v[black_y+d.first][black_x+d.second] != '#') {
          black_y += d.first;
          black_x += d.second;
          ++black_cnt;
        }
        if (v[black_y][black_x] == 'O')
          continue;

        int red_y = curr.first.first;
        int red_x = curr.first.second;
        int red_cnt = 0;
        while (v[red_y][red_x] != 'O' &&
               v[red_y+d.first][red_x+d.second] != '#') {
          red_y += d.first;
          red_x += d.second;
          ++red_cnt;
        }
        if (v[red_y][red_x] == 'O') {
          is_possible = true;
          break;
        }

        if (black_y == red_y &&
            black_x == red_x) {
          if (black_cnt > red_cnt) {
            black_y -= d.first;
            black_x -= d.second;
          } else {
            red_y -= d.first;
            red_x -= d.second;
          }
        }

        if (is_visited[red_y][red_x][black_y][black_x])
          continue;
        is_visited[red_y][red_x][black_y][black_x] = true;
        q.push({{red_y, red_x}, {black_y, black_x}});
      }
      if (is_possible)
        break;
    }
    if (time == 10 || is_possible)
      break;
    ++time;
  }
  std::cout << (time > 10 || !is_possible ? -1 : time);

  return 0;
}
