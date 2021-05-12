// http://icpc.me/15990
#include <bits/stdc++.h>

using namespace std;

long long d[100'005][4]; // 0, 1 ~ 100,000, OOB
// [][0] => unused
// [][1] => ... + '1';
// [][2] => ... + '2';
// [][3] => ... + '3';

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int t;

  cin >> t;
	d[1][1] = 1; // '1';
	d[2][2] = 1; // '2';
	d[3][1] = 1; // 2 + '1';
	d[3][2] = 1; // 1 + '2';
	d[3][3] = 1; // '3';
  for (int i = 4; i <= 100'000; ++i) {
		d[i][1] = (d[i-1][2] + d[i-1][3]) % 1'000'000'009;
		d[i][2] = (d[i-2][1] + d[i-2][3]) % 1'000'000'009;
		d[i][3] = (d[i-3][1] + d[i-3][2]) % 1'000'000'009;
  }
  while (t--) {
    int n;

    cin >> n;
    cout << (d[n][1] + d[n][2] + d[n][3]) % 1'000'000'009 << '\n';
  }

  return 0;
}