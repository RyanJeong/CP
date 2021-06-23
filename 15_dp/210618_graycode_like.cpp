// http://icpc.me/10844
/*

	0 - 1 : 1
0 - 1 - 2 : 2
2 - 3 - 4 : 2 
   ...
8 - 9 - 0 : 2

ex. d (0: 0으로 시작하는 수는 없다.)
-----
	1
	2
	3
	4
	5
	6
	7
	8
	9

ex. 1dd
------
	10 -> 1
	11 -> 0 or 2
	...
	18 -> 7 or 9
	19 -> 8
*/
#include <bits/stdc++.h>

using namespace std;

int dp[101][10]; // 1~100 | 0~9
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	cin>>n;
	for (int i = 1; i<=9; ++i) {
		dp[1][i]=1;
	}
	for (int i = 2; i<=n; ++i) {
		dp[i][0]=dp[i-1][1];
		for (int j = 1; j<=8; ++j) {
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1'000'000'000;
		}
		dp[i][9]=dp[i-1][8];
	}
	int sum = 0;
	for (int i = 0; i<=9; ++i) {
		sum+=dp[n][i];
		sum%=1'000'000'000;
	}
	cout<<sum;

	return 0;
}