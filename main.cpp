//http://icpc.me/1261
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
	cin >>m>>n;
	bool arr[n+1][m+1];
	for (int i = 1; i<=n; ++i) {
		string s;
		cin >> s;

		int j = 1;
		for (char c : s) {
			arr[i][j++]=(c=='0')?0:1;
		}
	}


	return 0;
}