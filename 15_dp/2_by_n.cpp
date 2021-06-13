// http://icpc.me/11726
#include <bits/stdc++.h>

using namespace std;

int d[1'002]; // 0, 1 ~ 1,000, OOB

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i<=n; ++i) {
        d[i] = (d[i-1]+d[i-2])%10'007;
    }
    cout << d[n];

    return 0;
}