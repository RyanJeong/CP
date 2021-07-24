#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[101][101];
    static long long dp[101][101];
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
        }
    }
    dp[1][1]=1;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (i==n && j==n) {
                continue;
            }
            if (!dp[i][j]) {
                continue;
            }
            int d = arr[i][j];
            if (i+d<=n) {
                dp[i+d][j]+=dp[i][j];
            }
            if (j+d<=n) {
                dp[i][j+d]+=dp[i][j];
            }
        }
    }
    cout << dp[n][n];

    return 0;
}