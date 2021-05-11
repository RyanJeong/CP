// http://icpc.me/1463
#include <bits/stdc++.h>

using namespace std;

int d[1'000'002]; // 0, 1 ~ 1,000,000, OOB

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  d[1] = 0;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i-1] + 1;
    if (!(i % 2)) {
      d[i] = min(d[i], d[i/2] + 1);
    }
    if (!(i % 3)) {
      d[i] = min(d[i], d[i/3] + 1);
    }
  }
  cout << d[n];

  return 0;
}
