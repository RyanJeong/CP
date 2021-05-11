// http://icpc.me/11053
#include <bits/stdc++.h>

using namespace std;

int arr[1'002];
int d[1'002];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  int result = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    int temp = 0;

    for (int j = 1; j < i; ++j) {
      if (arr[i] > arr[j]) {
        temp = max(temp, d[j]);
      }
    }
    d[i]   = temp + 1;
    result = max(result, d[i]);
  }
  cout << result;

  return 0;
}
