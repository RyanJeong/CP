// http://icpc.me/1477
#include <bits/stdc++.h>

using namespace std;

int line[102]; // ~ 100, OOB

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, l;

  cin >> n >> m >> l;
  line[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> line[i];  
  }
  line[n+1] = l; // 0, 1 ~ n-1, n => n + 2
  n += 2;
  sort(line, line + n);

  int low  = 0;
  int high = l;

  while (low <= high) {
    int mid = (low + high) / 2;
    int cnt = 0;

    for (int i = 1; i < n; ++i) {
      // line[i] = 7, line[i-1] = 3, gap = 4? -> -1
      cnt += (line[i] - line[i-1] - 1) / mid;
    }
    if (cnt > m) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << low;

  return 0;
}