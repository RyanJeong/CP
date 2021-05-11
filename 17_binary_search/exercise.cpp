// http://icpc.me/1920
#include <bits/stdc++.h>

using namespace std;

int a[100'005];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);
  int m;

  cin >> m;
  while (m--) {
    int t;

    cin >> t;
    cout << binary_search(a, a + n, t) << '\n';
  }

  return 0;
}