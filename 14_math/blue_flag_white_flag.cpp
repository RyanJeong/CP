// http://icpc.me/15736
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

	long long n;
	int       res = 0;

	cin >> n;
	for (long long i = 1; i * i <= n; ++i) {
		++res;
	}
	cout << res;

  return 0;
}
