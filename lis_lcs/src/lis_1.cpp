// https://www.acmicpc.net/problem/11053
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[1'001];
    static int lis[1'001];
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        cin>>arr[i];
    }

    // O(n^2)
    int res = 1;
    lis[1]=1;
    for (int i = 2; i<=n; ++i) {
        for (int j = 1; j<i; ++j) {
            if (arr[i]>arr[j]) {
                lis[i]=max(lis[i],lis[j]+1);
            }
            else {
                lis[i]=max(lis[i],1);
            }
        }
        res=max(res,lis[i]);
    }
    cout << res;

    return 0;
}