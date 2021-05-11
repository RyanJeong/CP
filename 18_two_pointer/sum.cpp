// http://icpc.me/2003
#include <bits/stdc++.h>

using namespace std;

int arr[10'002];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m;

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  int low  = 0;
  int high = 0;
  int res  = 0;
  int sum  = 0;
  
  while (high <= n) {
    if (sum > m) {
      sum -= arr[low++];
    } else if (sum < m) {
      sum += arr[high++];
    } else {
      ++res;
      sum -= arr[low++];
    }
  }
  cout << res;

  return 0;
}