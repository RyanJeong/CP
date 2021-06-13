// http://icpc.me/4179
#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

string arr[1001];       // #: wall, .: path, J: entry point, F: fire
int    man[1001][1001]; // 0: not visited, 1: visited
int    fire[1001][1001];

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin>>r>>c;
    queue<pair<int, int>> q_man, q_fire;

    for (int i = 0; i<r; ++i) {
        cin>>arr[i]; 
        for (int j = 0; j<c; ++j) {
            if (arr[i][j]=='F') {
                q_fire.push({i,j});
                fire[i][j]=1;
            } else if (arr[i][j]=='J') {
                q_man.push({i,j});
                man[i][j]=1;
            }
        }
    }
    while (!q_fire.empty()) {
        auto cur = q_fire.front();
        q_fire.pop();

        for (int i = 0; i<4; ++i) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (x<0 || x>=r) {
                continue;
            }
            if (y<0 || y>=c) {
                continue;
            }
            if (fire[x][y] || arr[x][y]=='#') {
                continue;
            }
            fire[x][y]=fire[cur.X][cur.Y]+1;
            q_fire.push({x,y});
        }
    }
    while (!q_man.empty()) {
        auto cur = q_man.front();
        q_man.pop();

        for (int i = 0; i<4; ++i) {
            int x = cur.X + dx[i];
            int y = cur.Y + dy[i];
            if (x<0 || x>=r || y<0 || y>=c) {
                cout << man[cur.X][cur.Y];

                return 0;
            }
            if (man[x][y] || arr[x][y]=='#') {
                continue;
            }
            // +1: man's movement
            if (fire[x][y] && fire[x][y] <= man[cur.X][cur.Y]+1) { // fire has broke out && fire spread before a man ran away.
                continue;
            }
            man[x][y] = man[cur.X][cur.Y]+1;
            q_man.push({x,y});
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}