// https://www.acmicpc.net/problem/1806
#include <bits/stdc++.h>

using namespace std;

int arr[100'001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin>>n>>s;
    for (int i = 1; i<=n; ++i) {
        cin >> arr[i];
    }

    int low  = 1;
    int high = 1;
    int sum = 0;
    int len = 2e9;
    while (high<=n) {
        if (sum<s) {
            sum+=arr[high++];
        }
        else {
            len=min(len,high-low);
            sum-=arr[low++];
        }
    }
    cout << ((len==2e9) ? 0 : len);

    return 0;
}