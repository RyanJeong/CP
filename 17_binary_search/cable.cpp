// http://icpc.me/1654
#include <bits/stdc++.h>

using namespace std;

int line[10'002];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int k, n;

  cin >> k >> n;
  for (int i = 0; i < k; ++i) {
    cin >> line[i];
  }
  sort(line, line + k);
  long long low  = 1;
  long long high = line[k-1];
  int       res  = 0;

  while (low <= high) {
    long long mid = (low + high) / 2;
    int       cnt = 0;

    for (int i = 0; i < k; ++i) {
      cnt += line[i] / mid;
    }
    // max
    if (cnt >= n) {
      low = mid + 1;
      res = mid;
    } else {
      high = mid - 1;
    }
  }
  cout << res;

  return 0;
}