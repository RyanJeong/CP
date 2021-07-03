// http://icpc.me/1261
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // right -> bottom -> left -> top
    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,1,0,-1}; 
    const int d_size = sizeof dx/sizeof(int);

    int n, m;
    cin>>m>>n;
    int dist[n+1][m+1];
    memset(dist,-1,sizeof dist);
    bool arr[n+1][m+1];
    for (int i = 1; i<=n; ++i) {
        string s;
        cin>>s;

        int j = 1;
        for (char c : s) {
            arr[i][j++]=c-'0';
        }
    }
    queue<pair<int, int>> q;
    q.push({1,1});
    dist[1][1]=0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (int d = 0; d<d_size; ++d) {
            int x = cur.first+dx[d];
            int y = cur.second+dy[d];

            if (x<1 || x>n) {
                continue;
            }
            if (y<1 || y>m) {
                continue;
            }
            if (dist[x][y]!=-1 && dist[x][y]<=dist[cur.first][cur.second]+arr[x][y]) {
                continue;
            }
            q.push({x,y});
            dist[x][y]=dist[cur.first][cur.second]+arr[x][y];
        }
    }
    cout << dist[n][m];

    return 0;
}