// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1: object, 0: none
    static int arr[501][501];        
    // 1: true,   0: false
    static bool is_visited[501][501];
    // right -> bottom -> left -> top
    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,1,0,-1}; 

    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>arr[i][j];
        }
    }

    int max_area = 0;
    int n_picture = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (is_visited[i][j] || !arr[i][j]) {
                continue;
            }
            int area = 0;
            ++n_picture;
            queue<pair<int, int>> q;
            q.push({i,j});
            is_visited[i][j]=true;
            
            while (!q.empty()) {
                ++area;
                auto cur = q.front();
                q.pop();
                for (int d = 0; d<4; ++d) {
                    int x = cur.first+dx[d];
                    int y = cur.second+dy[d];
                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (is_visited[x][y] || !arr[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    is_visited[x][y]=true;
                }
            }
            max_area = max(max_area, area);
        }
    }
    cout << n_picture << '\n' << max_area;

    return 0;
}

