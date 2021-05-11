// http://icpc.me/12852
#include <bits/stdc++.h>

using namespace std;

int d[1'000'002]; // 0, 1 ~ 1,000,000, OOB
int p[1'000'002]; // path

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  d[1] = 0;
  p[1] = 0;
  for (int i = 2; i <= n; ++i) {
    d[i] = d[i-1] + 1;
    p[i] = i - 1;
    if (!(i % 2)) {
      if (d[i] > d[i/2] + 1) {
        d[i] = d[i/2] + 1;
        p[i] = i / 2;
      }
    }
    if (!(i % 3)) {
      if (d[i] > d[i/3] + 1) {
        d[i] = d[i/3] + 1;
        p[i] = i / 3;
      }
    }
  }
  cout << d[n] << '\n';
  while (n) {
    cout << n << ' ';
    n = p[n];
  }

  return 0;
}

