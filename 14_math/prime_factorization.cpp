// http://icpc.me/11653
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      cout << i << '\n';
      n /= i;
    }
  }
  if (n != 1) {
    cout << n;
  }

  return 0;
}