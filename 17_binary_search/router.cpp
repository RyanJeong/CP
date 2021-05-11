// http://icpc.me/2110
#include <bits/stdc++.h>

using namespace std;

int line[200'002]; // 2 ~ 200,000, OOB

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, c;

  cin >> n >> c;
  for (int i = 0; i < n; ++i) {
    cin >> line[i];
  }
  sort(line, line + n);
  int low  = 1;
  int high = line[n-1] - line[0];
  int res  = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    int cnt = 1;
    int start = line[0];

    for (int i = 1; i < n; ++i) {
      // cnt : 1, line[i]: 4, line[i-1]: 2, gap: 2
      // -> cnt: 2
      // line[i]: 7, line[i-1]: 4, gap: 2
      // -> cnt: 3
      if (line[i] - start >= mid) {
        ++cnt;
        start = line[i];
      }
    }
    if (cnt >= c) {
      low = mid + 1;
      res = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << res;

  return 0;
}