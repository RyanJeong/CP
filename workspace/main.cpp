// https://www.acmicpc.net/problem/2458
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> d(n+1,vector<int>(n+1));
    fill(d.begin(),d.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        d[i][i]=0;
    }
    while (m--) {
        int a, b;
        cin>>a>>b;
        d[a][b]=1;
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i<=n; ++i) {
        bool is_succeed = true;
        for (int j = 1; j<=n; ++j) {
            if (d[i][j]!=1e9) {
                continue;
            }
            if (d[j][i]!=1e9) {
                continue;
            }
            is_succeed=false;
            break;
        }
        if (is_succeed) {
            ++res;
        }
    }
    cout << res;

    return 0;
}