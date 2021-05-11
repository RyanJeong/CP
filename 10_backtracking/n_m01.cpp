// http://icpc.me/15649
#include <bits/stdc++.h>

using namespace std;

void rec(int);

int  n, m;
int  arr[9]; // 0, 1 ~ 8
bool is_used[9];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  rec(0);
  return 0;
}

void rec(int s)
{
  if (s == m) {
    for (int i = 0; i < m; ++i) {
      cout << arr[i] << ' ';
    }
    cout <<'\n';

    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (!is_used[i]) {
      arr[s] = i;
      is_used[i] = true;
      rec(s + 1);
      is_used[i] = false;
    }
  }

  return;
}