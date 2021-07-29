// http://icpc.me/2217
#include <bits/stdc++.h>

using namespace std;

int d[100'002]; // 0, 1 ~ 100,000, OOB

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        cin>>d[i];
    }

    sort(d,d+n);
    for (int i = 1; i<=n; ++i) {
        ans = max(ans,d[n-i]*i);
    }
    cout << ans;

    return 0;
}