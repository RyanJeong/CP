// http://icpc.me/1012
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int  arr[50][50];        // 1: object, 0: none
bool is_visited[50][50]; // 1: true,   0: false

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--) {
        memset(arr,0,sizeof arr);
        memset(is_visited,false,sizeof is_visited);
        int m,n,k;
        cin>>m>>n>>k;
        int num = 0;

        while (k--) {
            int i,j;

            cin>>i>>j;
            arr[i][j] = 1;
        }
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (!arr[i][j] || is_visited[i][j]) {
                    continue;
                }

                queue<pair<int,int>>q;
                q.push({i,j});
                is_visited[i][j]=true;

                while (!q.empty()) {
                    pair<int,int> cur = q.front();
                    q.pop();
                    for (int k = 0; k<4; ++k) {
                        int x = cur.X+dx[k];
                        int y = cur.Y+dy[k];
                        if (x<0 || x>=m) {
                            continue;
                        }
                        if (y<0 || y>=n) {
                            continue;
                        }
                        if (is_visited[x][y] || arr[x][y]==0) {
                            continue;
                        }
                        is_visited[x][y]=true;
                        q.push({x,y});
                    }
                }
                ++num;
            }
        }
        cout << num << '\n';
    }

    return 0;
}