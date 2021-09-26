// https://www.acmicpc.net/problem/14588
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i].first>>v[i].second;
    }

    vector<vector<int>> d(n+1,vector<int>(n+1));
    fill(d.begin(),d.end(),vector<int>(n+1,1e9));
    for (int i = 1; i<=n; ++i) {
        d[i][i]=0;
    }
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            if (i==j) {
                continue;
            }

            /* 
                     -----      i
                ---        ---- j
            */
            if (v[j].second<v[i].first || v[i].second<v[j].first) {
                continue;
            }
            d[i][j]=1;
            d[j][i]=1;
        }
    }
    for (int k = 1; k<=n; ++k) {
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }

    int q;
    cin>>q;
    while (q--) {
        int a, b;
        cin>>a>>b;
        cout << ((d[a][b]==1e9) ? -1 : d[a][b]) << '\n';
    }

    return 0;
}