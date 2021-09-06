// https://www.acmicpc.net/problem/2559
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    
    int res = -1e9; // -100*k
    for (int i = k; i<=n; ++i) {
        res=max(res,v[i]-v[i-k]);
    }
    cout << res;

    return 0;
}
