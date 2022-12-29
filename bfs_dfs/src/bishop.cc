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

enum {
  kWhite,
  kBlack
};

void bt(int row, int col, int cnt, bool is_black);

bool is_allowed[11][11];  // 1 ~ 10
bool is_used1[21];        // diagonal (y = -x) (2n-1)
bool is_used2[21];        // diagonal (y = x) (2n-1)
int n;
int ans[2];               // [0]: white's cnt, [1]: black's cnt

int main() {
  CP;

  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j)
      std::cin >> is_allowed[i][j];
  }
  bt(1, 1, 0, kWhite);
  bt(1, 2, 0, kBlack);
  std::cout << ans[kWhite] + ans[kBlack];

  return 0;
}

void bt(int r, int c, int cnt, bool type) {
  if (c > n) {
  /*
    W B W
    B W B
    W B W
    (1, 3) -> (2, 2)
    (1, 2) -> (2, 1)
  */
    ++r;
    c = (c & 01) + 1;  // odd->even, even->odd;
  }

  if (r > n) {
    ans[type] = std::max(ans[type], cnt);

    return;
  }

  if (is_allowed[r][c] && !is_used1[r+c-n] && !is_used2[-r+c+n-1]) {
  /*
  (1, 2) (2, 2)
  (1, 1) (2, 1)

    1) y=-x (r+c)
      3 4
      2 3

    to use from index zero -> n = 2, r+c-n
      1 2
      0 1

    2) y=x (-r+c);
      1 0
      0 -1

    to use from index zero -> n = 2, -r+c+n-1
      2 1
      1 0
  */
    is_used1[r+c-n] = true;
    is_used2[-r+c+n-1] = true;
    bt(r, c + 2, cnt + 1, type);
    is_used1[r+c-n] = false;
    is_used2[-r+c+n-1] = false;
  }
  bt(r, c + 2, cnt, type);

  return;
}
