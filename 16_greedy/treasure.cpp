// http://icpc.me/1026
#include <bits/stdc++.h>

using namespace std;

int a[102];
int b[102]; // 0 ~ 99, OOB

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  int min = 0;

  for (int i = 0; i < n; ++i) {
    min += a[i] * b[n-i-1];
  }
  cout << min;

  return 0;
}