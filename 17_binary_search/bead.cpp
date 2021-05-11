// http://icpc.me/2613
#include <bits/stdc++.h>

using namespace std;

int line[302]; // 0 ~ 299

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;

  cin >> n >> m;
  int sum  = 0;
  int low  = 0;
  int high = 1;

  for (int i = 0; i < n; ++i) {
    cin >> line[i];
    sum += line[i];
    low = max(low, line[i]); // at least one element
  }
  high = sum;
  
  while (low <= high) {
    int mid     = (low + high) / 2;
    int cnt     = 1;

    // cout << "High: " << high << ", Low: " << low << ", Mid: " << mid << '\n';
    sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += line[i];
      if (sum > mid) {
        sum = line[i];
        ++cnt;
      }
    }
    if (cnt > m) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  cout << low << '\n';
  int size = 0;
  
  sum = 0;
  for (int i = 0; i < n ; ++i) {
    sum += line[i];
    if (sum > low) {
      sum = line[i];
      cout << size << ' ';
      size = 0;
      --m;
    }
    ++size;
    if (n - i == m) {
      break;
    }
  }
  while (m--) {
    cout << size << ' ';
    size = 1;
  }
  
  return 0;
}