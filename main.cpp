//http://icpc.me/1600
#include <bits/stdc++.h>

using namespace std;

// { w, h, k }
int dist[201][201][31]; // 0, 1 ~ w | h | k

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // movement
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
	// knight's movement
	const int knight_dx[] = {1,2,2,1,-1,-2,-2,-1};
	const int knight_dy[] = {2,1,-1,-2,-2,-1,1,2};

	int k;
	cin>>k;
    int w, h;
    cin>>w>>h;
	bool arr[201][201]; 
    for (int i = 1; i<=w; ++i) {
        for (int j = 1; j<=h; ++j) {
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({make_pair(0,0),0});
    
    //bfs
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        //1. general movement
        for (int d = 0; d<4; ++d) {
            int x = cur.first.first+dx[d];
            int y = cur.first.second+dy[d];
            int z = cur.second;

            if (x<1 || x>w) {
                continue;
            }
            if (y<1 || y>h) {
                continue;
            }
            // wall
            if (arr[x][y]) {
                continue;
            }
            if (dist[x][y][z]>=dist[cur.first.first][cur.first.second][z]+1) {
                continue;
            }
            dist[x][y][z]=dist[cur.first.first][cur.first.second][z]+1;
            q.push({make_pair(x,y),z});
        }
        //2. knight's movement
        for (int d = 0; d<8; ++d) {
            int x = cur.first.first+knight_dx[d];
            int y = cur.first.second+knight_dy[d];
            int z = cur.second;

            if (x<1 || x>w) {
                continue;
            }
            if (y<1 || y>h) {
                continue;
            }
            // wall
            if (arr[x][y]) {
                continue;
            }
            // no longer available
            if (z>=k) {
                continue;
            }
            if (dist[x][y][z+1]>=dist[cur.first.first][cur.first.second][z]+1) {
                continue;
            }
            dist[x][y][z+1]=dist[cur.first.first][cur.first.second][z]+1;
            q.push({make_pair(x,y),z+1});
        }
    }
    int min_movement = dist[w][h][0];
    for (int i = 1; i<=k; ++i) {
        if (dist[w][h][i]) {
            min_movement=min(min_movement,dist[w][h][i]);
        }
    }
    cout << ((min_movement) ? min_movement : -1);

    return 0;
}