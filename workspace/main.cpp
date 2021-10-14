#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<vector<int>> v(n+1,vector<int>(n+1)); // 1-based
    int s_x, s_y;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>v[i][j];
            if (v[i][j]==9) {
                s_x=i;
                s_y=j;
                v[i][j]=0;
            }
        }
    }

    int cnt = 0;
    int lv = 2;
    int lv_cnt = lv;
    vector<vector<int>> dist(n+1,vector<int>(n+1));
    while (true) {
        fill(dist.begin(),dist.end(),vector<int>(n+1,-1));
        queue<pair<int, int>> q;
        q.push({s_x,s_y});
        dist[s_x][s_y]=0;
        int d_x = -1;
        int d_y = -1;
        int min_dist = 1e9;
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
                if (y<1 || y>n) {
                    continue;
                }
                if (dist[x][y]>=0 || v[x][y]>lv) {
                    continue;
                }
                q.push({x,y});
                dist[x][y]=dist[cur.first][cur.second]+1;

                if (!v[x][y] || v[x][y]>=lv) {
                    continue;
                }
                if (min_dist>dist[x][y]) {
                    d_x=x;
                    d_y=y;
                    min_dist=dist[x][y];
                }
                else if (min_dist==dist[x][y]) {
                    // 가장 위쪽
                    if (d_x>x) { 
                        d_x=x;
                        d_y=y;
                    }
                    // 가장 위쪽에 여러마리가 있다면, 가장 왼쪽
                    else if (d_x==x && d_y>y) {
                        d_x=x;
                        d_y=y;
                    }
                }
            }
        }
        if (d_x==-1 && d_y==-1) {
            break;
        }
        cnt+=dist[d_x][d_y];
        v[d_x][d_y]=0;
        s_x=d_x;
        s_y=d_y;

        --lv_cnt;
        if (!lv_cnt) {
            ++lv;
            lv_cnt=lv;
        }
    }
    cout << cnt;

    return 0;
}