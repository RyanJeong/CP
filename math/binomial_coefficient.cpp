// nCk=n!/(n−k)!k!
// https://www.acmicpc.net/problem/11050
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int res = 1;
    int n, k;
    cin>>n>>k;

    for (int i = 1; i<=n; ++i) {
        res*=i; // n!
    }
    for (int i = 1; i<=k; ++i) {
        res/=i; // n! / k!
    }
    for (int i = 1; i<=n - k; ++i) {
        res/=i; // n! / k!(n-k)!
    }
    cout << res;

    return 0;
}