// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    vector<int> areas;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (is_visited[i][j] || !v[i][j]) {
                continue;
            }

            int area = 0;
            queue<pair<int, int>> q;
            q.push({i,j});
            is_visited[i][j]=true;
            while (!q.empty()) {
                ++area;
                auto cur = q.front();
                q.pop();

                for (int d = 0; d<4; ++d) {
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
                    if (is_visited[x][y] || !v[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    is_visited[x][y]=true;
                }
            }
            areas.push_back(area);
        }
    }
    sort(areas.begin(),areas.end());
    cout << areas.size()  << '\n' << ((!areas.empty()) ? areas.back() : 0);

    return 0;
}
