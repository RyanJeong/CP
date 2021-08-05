// https://www.acmicpc.net/problem/7576
#include <bits/stdc++.h>

using namespace std;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    queue<pair<int, int>> q;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
            if (v[i][j]==1) {
                --v[i][j];
                q.push({i,j});
                is_visited[i][j]=true;
            }
            else if (v[i][j]==-1) {
                is_visited[i][j]=true;
            }
        }
    }

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
            if (is_visited[x][y]) {
                continue;
            }
            q.push({x,y});
            is_visited[x][y]=true;
            v[x][y]=v[cur.first][cur.second]+1;
        }
    }

    int max_day = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (!is_visited[i][j]) {
                cout << -1;

                return 0;
            }
            max_day=max(max_day,v[i][j]);
        }
    }
    cout << max_day;

    return 0;
}
