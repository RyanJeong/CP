// http://icpc.me/1926
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int  arr[500][500];        // 1: object, 0: none
bool is_visited[500][500]; // 1: true,   0: false

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // warning, n, m <-> m, n
    int max_area = 0;
    int n_picture = 0;
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (arr[i][j]==0 || is_visited[i][j]) {
                continue;
            }
            int area = 0;
            queue<pair<int, int>> q;
            q.push({i,j});
            ++n_picture;
            is_visited[i][j]=true;

            while (!q.empty()) {
                ++area;
                // pair<int, int> cur = q.front(); 
                // auto cur = q.front();
                pair<int, int> cur = q.front(); 
                q.pop();

                for (int k = 0; k<4; ++k) {
                    int x = cur.X+dx[k];
                    int y = cur.Y+dy[k];
                    if (x<0 || x>=n) {
                        continue;
                    }
                    if (y<0 || y>=m) {
                        continue;
                    }
                    if (is_visited[x][y] || arr[x][y]==0) {
                        continue;
                    }
                    is_visited[x][y]=true;
                    q.push({x,y});
                }
            }
            max_area=max(max_area,area);
        }
    }
    cout << n_picture << '\n' << max_area;

    return 0;
}