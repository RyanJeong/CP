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
    int res = arr[n];
    dp[n] = arr[n];
    for (int i = n-1; i>0; --i) {
        for (int j = n; j>i; --j) {
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