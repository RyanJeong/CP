// https://www.acmicpc.net/problem/17404
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int r[1'001]; 
	static int g[1'001];
	static int b[1'001];
	static int dp[1'001][3]; 

	int n;
	cin>>n;
	for (int i = 1; i<=n; ++i) {
		cin>>r[i]>>g[i]>>b[i];
	}

	vector<int> ans;
	for (int i = 0; i<3; ++i) {
		// ignore other cases
		dp[1][0]=dp[1][1]=dp[1][2]=2e9;
		dp[1][i]=(i==0) ? r[1] : ((i==1) ? g[1] : b[1]);
		for (int i = 2; i<=n; ++i) {
			dp[i][0]=min(dp[i-1][1],dp[i-1][2])+r[i];
			dp[i][1]=min(dp[i-1][0],dp[i-1][2])+g[i];
			dp[i][2]=min(dp[i-1][0],dp[i-1][1])+b[i];
		}
		int idx1 = (i+1)%3;
		ans.push_back(dp[n][idx1]);
		int idx2 = (i+2)%3;
		ans.push_back(dp[n][idx2]);
	}
	sort(ans.begin(),ans.end());

    cout << ans.front();

	return 0;
}