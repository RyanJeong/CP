// https://www.acmicpc.net/problem/17626
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> dp(n+1);
    dp[1]=1;

    for (int i = 2; i<=n; ++i) {
        dp[i]=dp[1]+dp[i-1];
        for (int j = 2; j*j<=i; ++j) {
            dp[i]=min(dp[i],1+dp[i-j*j]);
        }
    }
    cout << dp[n];

    return 0;
}
