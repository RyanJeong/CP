// http://icpc.me/7536
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int arr[1001][1001]; //  1: object, 0: none
int day[1001][1001]; // -1: not used yet

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;
    queue<pair<int, int>> q;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            cin>>arr[i][j];
            if (arr[i][j]==1) {
                q.push({i,j});
            } 
            else if (arr[i][j]==0) {
                day[i][j]=-1;
            }
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int i = 0; i<4; ++i) {
            int x = cur.X+dx[i];
            int y = cur.Y+dy[i];
            if (x<0 || x>=n) {
                continue;
            }
            if (y<0 || y>=m) {
                continue;
            }
            if (day[x][y]!=-1) { // con't care
                continue;
            }
            day[x][y]=day[cur.X][cur.Y]+1;
            q.push({x,y});
        }
    }

    int n_day = 0;
    bool is_error = false;

    for (int i = 0; i<n && !is_error; ++i) {
        for (int j = 0; j<m; ++j) {
            if (day[i][j]==-1) { // not spread accoress the area
                is_error=true; 
                break;
            }
            n_day = max(n_day,day[i][j]);
        }
    }
    cout << ((is_error) ? -1 : n_day);

    return 0;
}