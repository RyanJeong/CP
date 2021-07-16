// https://www.acmicpc.net/problem/11660
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int s[1025][1025]; // s[i][j] = a_i,j+s_i-1,j+s_i,j-1-s_i-1,j-1
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            int a;
            cin>>a;
            s[i][j]=a+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout << s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] << '\n';
    }

    return 0;
}