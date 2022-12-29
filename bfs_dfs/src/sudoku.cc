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

bool bt(int row, int col);

// 1 2 3
// 4 5 6
// 7 8 9
int arr[9][9];
bool is_used1[3][3][10];  // subsquare
bool is_used2[9][10];     // row
bool is_used3[9][10];     // col

int main() {
  CP;

  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j) {
      char c;
      std::cin >> c;
      arr[i][j] = c - '0';

      // subsquare|row|col, digit
      is_used1[i/3][j/3][arr[i][j]] = true;
      is_used2[i][arr[i][j]] = true;
      is_used3[j][arr[i][j]] = true;
    }
    std::cin.ignore();  // consume '\n'
  }
  bt(0, 0);
  for (int i = 0; i < 9; ++i) {
    for (int j = 0; j < 9; ++j)
      std::cout << arr[i][j];
    std::cout << '\n';
  }

  return 0;
}

bool bt(int i, int j) {
  for (; i < 9; ++i) {
    for (; j < 9; ++j) {
      if (arr[i][j])
        continue;

      for (int n = 1; n <= 9; ++n) {
        if (is_used1[i/3][j/3][n] == false &&
            is_used2[i][n] == false &&
            is_used3[j][n] == false) {
          is_used1[i/3][j/3][n] = true;
          is_used2[i][n] = true;
          is_used3[j][n] = true;
          arr[i][j] = n;
          if (bt(i, j + 1))
            return true;

          is_used1[i/3][j/3][n] = false;
          is_used2[i][n] = false;
          is_used3[j][n] = false;
          arr[i][j] = 0;
        }
      }

      if (!arr[i][j])
        return false;
    }
    j = 0;
  }

  return true;
}
