// http://icpc.me/2579
#include <bits/stdc++.h>

using namespace std;

int d[302]; // except
int s[302];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  int total = 0;

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    total += s[i];
  }
  if (n <= 2) {
    cout << total;
  } else {
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    for (int i = 4; i <= n - 1; ++i) {
      d[i] = min(d[i-2], d[i-3]) + s[i];
    }
    cout << total - min(d[n-1], d[n-2]);
  }

  return 0;
}
