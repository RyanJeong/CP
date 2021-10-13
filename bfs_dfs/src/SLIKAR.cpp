// https://www.acmicpc.net/problem/3055
// 탈출 
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;
    vector<vector<char>> v(r+1,vector<char>(c+1)); // 1-based
    int d_x, d_y;
    int s_x, s_y;
    for (int i = 1; i<=r; ++i) {
        for (int j = 1; j<=c; ++j) {
            cin>>v[i][j];
            if (v[i][j]=='D') {
                d_x=i;
                d_y=j;
            }
            if (v[i][j]=='S') {
                s_x=i;
                s_y=j;
            }
        }
    }

    vector<vector<int>> dist(r+1,vector<int>(c+1));
    fill(dist.begin(),dist.end(),vector<int>(c+1,-1));
    for (int i = 1; i<=r; ++i) {
        for (int j = 1; j<=c; ++j) {
            if (v[i][j]=='D' || v[i][j]=='S' || v[i][j]=='X' || v[i][j]=='.') {
                continue;
            }

            queue<pair<int, int>> q;
            q.push({i,j});
            dist[i][j]=0;
            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                const vector<pair<int, int>> adjacency = {
                    {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                };
                for (auto d : adjacency) {
                    int x = cur.first+d.first;
                    int y = cur.second+d.second;

                    if (x<1 || x>r) {
                        continue;
                    }
                    if (y<1 || y>c) {
                        continue;
                    }
                    if (v[x][y]=='X' || v[x][y]=='D') {
                        continue;
                    }
                    if (dist[x][y]>=0) {
                        continue;
                    }
                    dist[x][y]=dist[cur.first][cur.second]+1;
                    q.push({x,y});
                }
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({s_x,s_y});
    dist[s_x][s_y]=0;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        if (cur.first==d_x && cur.second==d_y) {
            cout << dist[d_x][d_y];

            return 0;
        }

        const vector<pair<int, int>> adjacency = {
            {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
        };
        for (auto d : adjacency) {
            int x = cur.first+d.first;
            int y = cur.second+d.second;

            if (x<1 || x>r) {
                continue;
            }
            if (y<1 || y>c) {
                continue;
            }
            if (v[x][y]=='X') {
                continue;
            }
            if (dist[x][y]>=0 && dist[x][y]<=dist[cur.first][cur.second]+1) {
                continue;
            }
            dist[x][y]=dist[cur.first][cur.second]+1;
            q.push({x,y});
        }
    }
    cout << "KAKTUS";

    return 0;
}
