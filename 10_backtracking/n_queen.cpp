// http://icpc.me/9663
#include <bits/stdc++.h>

using namespace std;

// parameter: row
void rec(int);

bool is_used1[15]; // vertical
bool is_used2[30]; // diagonal (y = x)
bool is_used3[30]; // diagonal (y = -x)
int  n, cnt;       // count, <algorithm> have declared a var 'count'

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  rec(0);
  cout << cnt;

  return 0;
}

void rec(int row) 
{
  if (row == n) {
    ++cnt;

    return;
  }
  for (int i = 0; i < n; ++i) {
    if (is_used1[i] || is_used2[i+row] || is_used3[row-i+n-1]) {
      continue;
    }
    is_used1[i]         = true;
    is_used2[i+row]     = true;
    is_used3[row-i+n-1] = true; // { 3, 0 }, 0 - 3 + 4 - 1 = 0
    rec(row + 1);
    is_used1[i]         = false;
    is_used2[i+row]     = false;
    is_used3[row-i+n-1] = false;
  }

  return;
}
