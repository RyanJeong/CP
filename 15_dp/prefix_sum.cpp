// http://icpc.me/11659
#include <bits/stdc++.h>

using namespace std;

int a[100'002]; // 0, 1 ~ 100,000, OOB
int d[100'002]; // d(i) = a(1) + a(2) + ... + a(i)

// a(1) + a(2) + ... + a(i) = d[i] = d[i-1] + a(i)
// a(i) + ... + a(j)
// = d[j] - d[i-1]
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    for (int i = 1; i<=n; ++i) {
        cin>>a[i];
        d[i]=d[i-1]+a[i];
    }

    while (m--) {
        int i, j;
        cin>>i>>j;

        cout << d[j]-d[i-1] << '\n';
    }

    return 0;
}