// https://www.acmicpc.net/problem/11123
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<char>> v(n+1,vector<char>(m+1));
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=m; ++j) {
                cin>>v[i][j];
            }
        }

        vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
        int res = 0;
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=m; ++j) {
                if (v[i][j]=='.' || is_visited[i][j]) {
                    continue;
                }

                ++res;
                queue<pair<int, int>> q;
                q.push({i,j});
                is_visited[i][j]=true;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    const vector<pair<int, int>> adjacency = {
                        {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                    };
                    for (auto d : adjacency) {
                        int x = cur.first+d.first;
                        int y = cur.second+d.second;

                        if (x<1 || x>n) {
                            continue;
                        }
                        if (y<1 || y>m) {
                            continue;
                        }
                        if (v[x][y]=='.' || is_visited[x][y]) {
                            continue;
                        }
                        q.push({x,y});
                        is_visited[x][y]=true;
                    }
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
