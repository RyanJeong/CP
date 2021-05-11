// http://icpc.me/9466
#include <bits/stdc++.h>

using namespace std;

int arr[100'001];

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;
  while (t--) {
    int n;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    // 0: unused, -1: team, others: used
    vector<int> v(n + 1, 0); // n ints with value 0

    for (int i = 1; i <= n; ++i) {
      if (v[i]) {
        continue;
      }
      int cur = i;

      v[cur] = i;
      while (1) {
        cur = arr[cur];
        if (v[cur] == i) {
          v[cur] = -1;
          int temp;

          temp = arr[cur];
          // make a team
          while (temp != cur) {
            v[temp] = -1;
            temp = arr[temp];
          }
          break;
        }
        if (v[cur] == 0) {
          v[cur] = i;
          continue;
        } else {
          break;
        }
      }
    }
    int num = n;

    for (int i = 1; i <= n; ++i) {
      num -= (v[i] == -1);
    }
    cout << num << '\n';
  }
  return 0;
}