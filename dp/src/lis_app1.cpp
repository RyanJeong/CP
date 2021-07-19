// https://www.acmicpc.net/problem/11055
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[1'001];
    static int dp[1'001];
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        cin>>arr[i];
    }

    // O(n^2)
    int res = arr[1];
    dp[1] = arr[1];
    for (int i = 2; i<=n; ++i) {
        for (int j = 1; j<i; ++j) {
            if (arr[i]>arr[j]) {
                dp[i]=max(dp[i],dp[j]+arr[i]);
            }
            else {
                dp[i]=max(dp[i],arr[i]);
            }
        }
        res=max(res,dp[i]);
    }
    cout << res;

    return 0;
}
