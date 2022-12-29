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

void bt(int row);

bool is_used1[15];  // vertical
bool is_used2[30];  // diagonal (y = x)
bool is_used3[30];  // diagonal (y = -x)
int n, cnt;

int main() {
  CP;

  std::cin >> n;
  bt(0);
  std::cout << cnt;

  return 0;
}

void bt(int r) {
  if (r == n) {
    ++cnt;

    return;
  }

  for (int i = 0; i < n; ++i) {
    if (is_used1[i] || is_used2[i+r] || is_used3[r-i+n-1])
      continue;

    is_used1[i] = true;
    is_used2[i+r] = true;
    is_used3[r-i+n-1] = true;  // { 3, 0 }, 0 - 3 + 4 - 1 = 0
    bt(r + 1);
    is_used1[i] = false;
    is_used2[i+r] = false;
    is_used3[r-i+n-1] = false;
  }
}
