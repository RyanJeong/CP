// https://www.acmicpc.net/problem/16946
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
    cin>>n>>m;
    vector<vector<char>> v(n+1,vector<char>(m+1));
    queue<pair<int, int>> q_buf;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
            if (v[i][j]=='1') {
                q_buf.push({i,j});
            }
        }
    }

    vector<vector<int>> res(n+1,vector<int>(m+1));
    while (!q_buf.empty()) {
        queue<pair<int, int>> q;
        q.push(q_buf.front());
        vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
        int cnt = 0;
        while (!q.empty()) {
            ++cnt;
            auto cur = q.front();
            q.pop();

            for (int d = 0; d<4; ++d) {
                const int dx[] = {1,0,-1,0};
                const int dy[] = {0,-1,0,1};

                int x = cur.first+dx[d];
                int y = cur.second+dy[d];

                if (x<1 || x>n) {
                    continue;
                }
                if (y<1 || y>m) {
                    continue;
                }
                if (v[x][y]=='1' || is_visited[x][y]) {
                    continue;
                }
                is_visited[x][y]=true;
                q.push({x,y});
            }
        }
        res[q_buf.front().first][q_buf.front().second]=cnt;
        q_buf.pop();
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cout << res[i][j];
        }
        cout << '\n';
    }

    return 0;
}