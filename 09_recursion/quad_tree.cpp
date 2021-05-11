// http://icpc.me/1992
#include <bits/stdc++.h>

using namespace std;

int arr[64][64];

void rec(int, int, int);

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string str;

    cin >> str;
    for (int j = 0; j < n; ++j) {
      arr[i][j] = str[j] - '0';
    }
  }
  rec(n, 0, 0);

  return 0;
}

// row - column, y - x
void rec(int n, int y, int x) {
  if (n == 1) {
    cout << arr[y][x];

    return;
  }
  bool is_zero, is_one;

  is_zero = is_one = true;
  for (int i = y; i < y + n; ++i) {
    for (int j = x; j < x + n; ++j) {
      if (arr[i][j]) {
        is_zero = false;
      } else {
        is_one = false;
      }
    }
  }
  if (is_zero) {
    cout << 0;
  } else if (is_one) {
    cout << 1;
  } else {
    n /= 2;

    cout << '(';
    rec(n, y, x);
    rec(n, y, x + n);
    rec(n, y + n, x);
    rec(n, y + n, x + n);
    cout << ')';
  }

  return;
}