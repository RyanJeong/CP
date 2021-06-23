// http://icpc.me/2583
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

// { x, y }
int  arr[101][101];        // 1: object, 0: none
bool is_visited[101][101]; // 1: true,   0: false

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n_object = 0;
    int m, n, k; // y, x, iter
    cin>>m>>n>>k;

    for (int i = 0; i<k; ++i) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        for (int x = x1; x<x2; ++x) {
            for (int y = y1; y<y2; ++y) {
                arr[x][y] = 1;
            }
        }
    }
    vector<int> v;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (arr[i][j]==1 || is_visited[i][j]) {
                continue;
            }
            int area = 0;
            queue<pair<int, int>> q;
            q.push({ i, j });
            ++n_object;
            is_visited[i][j] = true;

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
                    if (is_visited[x][y] || arr[x][y]) {
                        continue;
                    }
                    is_visited[x][y]=true;
                    q.push({x,y});
                }
            }
            v.push_back(area);
        }
    }
    sort(v.begin(),v.end());
    cout << n_object << '\n';
    for (int i : v) {
        cout << i << ' ';
    }

    return 0;
}