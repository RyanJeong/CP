// https://www.acmicpc.net/problem/3187
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    vector<vector<char>> v(n+1,vector<char>(m+1)); // 1-based
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    int goats = 0;
    int wolves =0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (!is_visited[i][j] && v[i][j]!='#') {
                int goat = 0;
                int wolf = 0;
                if (v[i][j]=='v') {
                    ++wolf;
                }
                if (v[i][j]=='k') {
                    ++goat;
                }
                queue<pair<int, int>> q;
                q.push({i,j});
                is_visited[i][j]=true;
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
                        if (is_visited[x][y] || v[x][y]=='#') {
                            continue;
                        }
                        if (v[x][y]=='v') {
                            ++wolf;
                        }
                        if (v[x][y]=='k') {
                            ++goat;
                        }
                        q.push({x,y});
                        is_visited[x][y]=true;
                    }
                }
                if (goat>wolf) {
                    goats+=goat;
                }
                else {
                    wolves+=wolf;
                }
            }
        }
    }
    cout << goats << ' ' << wolves;

    return 0;
}
