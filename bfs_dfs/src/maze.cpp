// https://www.acmicpc.net/problem/2178
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(m+1));
    vector<vector<char>> v(n+1,vector<char>(m+1)); // 1-based
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1,1});
    dist[1][1]=1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d<4; ++d) {
            // right -> bottom -> left -> top
            const int dx[] = {1,0,-1,0};
            const int dy[] = {0,1,0,-1}; 

            int x = cur.first+dx[d];
            int y = cur.second+dy[d];
            if (x<1 || x>n) {
                continue;
            }
            if (y<1 || y>m) {
                continue;
            }
            // the vector `dist` can calculate distance
            // and check visit status at the same time
            if (dist[x][y] || v[x][y]=='0') {
                continue;
            }
            dist[x][y]=dist[cur.first][cur.second]+1;
            q.push({x,y});
        }
    }
    cout << dist[n][m];

    return 0;
}
