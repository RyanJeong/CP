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
#include <utility>
#include <cstring>

bool Dfs(int t1, int t2);

int arr[6][3];
int buf[6][3];

int main() {
  CP;

  for (int t = 0; t < 4; ++t) {
    memset(buf, 0, sizeof buf);

    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j)
        std::cin >> arr[i][j];
    }
    std::cout << Dfs(0, 1) << ' ';
  }

  return 0;
}

bool Dfs(int t1, int t2) {
  if (t2 == 6) {
    ++t1;
    t2 = t1 + 1;
  }

  if (t1 == 5) {
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (arr[i][j] == buf[i][j])
          continue;

        return false;
      }
    }

    return true;
  }

  ++buf[t1][0];
  ++buf[t2][2];
  if (Dfs(t1, t2 + 1))
    return true;
  --buf[t1][0];
  --buf[t2][2];

  ++buf[t1][1];
  ++buf[t2][1];
  if (Dfs(t1, t2 + 1))
    return true;
  --buf[t1][1];
  --buf[t2][1];

  ++buf[t1][2];
  ++buf[t2][0];
  if (Dfs(t1, t2 + 1))
    return true;
  --buf[t1][2];
  --buf[t2][0];

  return false;
}
