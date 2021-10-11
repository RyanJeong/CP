// https://www.acmicpc.net/problem/11066
#include <bits/stdc++.h>
 
using namespace std;
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int k;
        cin>>k;
        vector<int> v(k+1);
        vector<int> sum(k+1);
        for (int i = 1; i<=k; ++i) {
            cin>>v[i];
            sum[i]=sum[i-1]+v[i];
        }

        vector<vector<int>> dp(k+1,vector<int>(k+1));
        for (int d = 1; d<k; ++d) {
            // dp[i][j] = novel[i]+novel[i+1]+...+novel[j]
            for (int i = 1; i+d<=k; ++i) { 
                int j = i+d;
                dp[i][j]=1e9;

                for (int mid = i; mid<j; ++mid) {
                    dp[i][j]=min(dp[i][j],sum[j]+dp[i][mid]+dp[mid+1][j]-sum[i-1]);
                }
            }
        }
        cout << dp[1][k] << '\n';
    }

    return 0;
}