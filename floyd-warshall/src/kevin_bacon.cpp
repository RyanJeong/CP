// https://www.acmicpc.net/problem/1389
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
        d[b][a]=1;
    }

    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    int idx = 0;
    int min_edge = 1e9;
    for (int i = 1; i<=n; ++i) {
        int tmp = 0;
        for (int j = 1; j<=n; ++j) {
            tmp+=d[i][j];
        }
        if (min_edge>tmp) {
            min_edge=tmp;
            idx=i;
        }
    }
    cout << idx;

    return 0;
}
