// https://www.acmicpc.net/problem/16946
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n, m;
    cin>>n>>m;
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    vector<vector<char>> v(n+1,vector<char>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    vector<vector<int>> buf(n+1,vector<int>(m+1,-1));
    vector<int> areas;
    int area_idx = 0;
    queue<pair<int, int>> q;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (v[i][j]=='1' || is_visited[i][j]) {
                continue;
            }
            q.push({i,j});
            is_visited[i][j]=true;
            buf[i][j]=area_idx;
            int area_size = 0;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                ++area_size;
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
                    if (v[x][y]!='0' || is_visited[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    is_visited[x][y]=true;
                    buf[x][y]=area_idx;
                }
            }
            areas.push_back(area_size);
            ++area_idx;
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (v[i][j]=='1') {
                set<int> s; // remove dup. cases

                for (int d = 0; d<4; ++d) {
                    const int dx[] = {1,0,-1,0};
                    const int dy[] = {0,-1,0,1};

                    int x = i+dx[d];
                    int y = j+dy[d];
                
                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (buf[x][y]==-1) {
                        continue;
                    }
                    s.insert(buf[x][y]);
                }
                int cnt = 1;
                for (int idx : s) {
                    cnt += areas[idx];
                }
				cnt%=10;
                v[i][j]=cnt+'0';
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cout << v[i][j];
        }
        cout << '\n';
    }

    return 0;
}