// https://www.acmicpc.net/problem/2583
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, k;
    cin>>m>>n>>k;

    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    for (int i = 1; i<=k; ++i) {
        int x1, y1;
        cin>>x1>>y1;
        ++x1;
        ++y1;
        int x2, y2;
        cin>>x2>>y2;
        for (int x = x1; x<=x2; ++x) {
            for (int y = y1; y<=y2; ++y) {
                v[x][y]=1;
            }
        }
    }

    vector<int> n_obj;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (v[i][j]==1 || is_visited[i][j]) {
                continue;
            }

            int area = 0;
            queue<pair<int, int>> q;
            q.push({i,j});
            is_visited[i][j]=true;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();
                ++area;

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
                    if (is_visited[x][y] || v[x][y]) {
                        continue;
                    }
                    is_visited[x][y]=true;
                    q.push({x,y});
                }
            }
            n_obj.push_back(area);
        }
    }
    sort(n_obj.begin(),n_obj.end());
    cout << n_obj.size() << '\n';
    for (int i : n_obj) {
        cout << i << ' ';
    }

    return 0;
}

