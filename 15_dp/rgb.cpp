// http://icpc.me/1149
#include <bits/stdc++.h>

using namespace std;

int r[1'002], g[1'002], b[1'002];
int d[1'002][3]; // weight, num

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 1; i<=n; ++i) {
        cin>>r[i]>>g[i]>>b[i];
    }
    d[1][0]=r[1];
    d[1][1]=g[1];
    d[1][2]=b[1];
    for (int i = 2; i<=n; ++i) {
        d[i][0]=min(d[i-1][1],d[i-1][2])+r[i];
        d[i][1]=min(d[i-1][0],d[i-1][2])+g[i];
        d[i][2]=min(d[i-1][0],d[i-1][1])+b[i];
    }
    cout << min({d[n][0],d[n][1],d[n][2]});

    return 0;
}