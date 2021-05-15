// http://icpc.me/7453
// upper_bound & lower_bound
// iterator - base(begin) = offset
#include <bits/stdc++.h>

using namespace std;

int arr[4000][4];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      cin >> arr[i][j];
    }
  }
  vector<long long> v;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      v.push_back(arr[i][0] + arr[j][1]);
    }
  }
  sort(v.begin(), v.end());
  long long res = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      long long temp = arr[i][2] + arr[j][3];
      long long low  = lower_bound(v.begin(), v.end(), (-temp)) - v.begin();
      long long high = upper_bound(v.begin(), v.end(), (-temp)) - v.begin();

      if (temp + v[low]) {
        continue;
      }
      res += (high - low);
    }
  }
  cout << res;

  return 0;
}