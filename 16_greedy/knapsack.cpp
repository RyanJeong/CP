// http://icpc.me/12865
#include <bits/stdc++.h>

using namespace std;

int d[100'002]; // 0, 1 ~ 100,000, OOB
int w[102]; // 0, 1 ~ 100, OOB
int v[102]; // 0, 1 ~ 100, OOB

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i] >> v[i];
  }
  for (int i = 1; i <= n; ++i) {
    int value = v[i];

    for (int j = k; w[i] <= j; --j) {
      d[j] = max(d[j], d[j-w[i]] + value);
    }
  }
  cout << d[k];

  return 0;
}