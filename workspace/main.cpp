#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1)); // 1-based;
    vector<pair<int, int>> empty_area;
    int wall_size = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
            if (v[i][j]==0) {
                empty_area.push_back({i,j});
            }
            else if (v[i][j]==1) {
                ++wall_size;
            }
        }
    }

    int empty_size = empty_area.size();
    int res = n*m;
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    for (int first = 0; first<empty_size-2; ++first) {
        int first_x = empty_area[first].first;
        int first_y = empty_area[first].second;
        v[first_x][first_y]=1;
        for (int second = first+1; second<empty_size-1; ++second) {
            int second_x = empty_area[second].first;
            int second_y = empty_area[second].second;
            v[second_x][second_y]=1;
            for (int third = second+1; third<empty_size; ++third) {
                int third_x = empty_area[third].first;
                int third_y = empty_area[third].second;
                v[third_x][third_y]=1;

                fill(is_visited.begin(),is_visited.end(),vector<bool>(m+1,false));
                queue<pair<int, int>> q;
                for (int i = 1; i<=n; ++i) {
                    for (int j = 1; j<=m; ++j) {
                        if (v[i][j]==0 || v[i][j]==1) {
                            continue;
                        }
                        q.push({i,j});
                        is_visited[i][j]=true;
                    }
                }

                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    const vector<pair<int, int>> adjacency = {
                        {0,1},{-1,0},{0,-1},{1,0}
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
                        if (is_visited[x][y]) {
                            continue;
                        }
                        if (v[x][y]==1) {
                            continue;
                        }
                        is_visited[x][y]=true;
                        q.push({x,y});
                    }
                }

                int cnt = 0;
                for (int i = 1; i<=n; ++i) {
                    for (int j = 1; j<=m; ++j) {
                        if (is_visited[i][j]) {
                            ++cnt;
                        }
                    }
                }
                res=min(res,cnt);
                v[third_x][third_y]=0;
            }
            v[second_x][second_y]=0;
        }
        v[first_x][first_y]=0;
    }
    cout << n*m-(wall_size+3)-res; // 0<->1+2

    return 0;
}