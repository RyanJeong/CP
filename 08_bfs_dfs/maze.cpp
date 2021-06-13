// http://icpc.me/2178
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

string arr[100];       // '1' : path, '0': wall
int dist[100][100]; // positive number: dist., 0: not visited

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // warning, n, m <-> m, n
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i]; 
    }
    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0]=1;

    while (!q.empty()) {
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
            if (dist[x][y] || arr[x][y]=='0') {
                continue;
            }
            dist[x][y]=dist[cur.X][cur.Y]+1;
            q.push({x,y});
        }
    }
    cout << dist[n-1][m-1];

    return 0;
}