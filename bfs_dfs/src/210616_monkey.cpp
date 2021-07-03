//http://icpc.me/1600
#include <bits/stdc++.h>

using namespace std;

// { h, w, k }
int dist[201][201][31]; // 1 ~ w | h, 0 ~ k

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist,-1,sizeof dist);
    // movement
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,-1,0,1};
    // knight's movement
    const int knight_dx[] = {1,2,2,1,-1,-2,-2,-1};
    const int knight_dy[] = {2,1,-1,-2,-2,-1,1,2};

    int k;
    cin>>k;
    int w, h;
    cin>>w>>h;
    bool arr[201][201]; 
    for (int i = 1; i<=h; ++i) {
        for (int j = 1; j<=w; ++j) {
            cin>>arr[i][j];
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({make_pair(1,1),0});
    dist[1][1][0]=0;
    
    //bfs
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        //1. general movement
        for (int d = 0; d<4; ++d) {
            int x = cur.first.first+dx[d];
            int y = cur.first.second+dy[d];
            int z = cur.second;

            if (x<1 || x>h) {
                continue;
            }
            if (y<1 || y>w) {
                continue;
            }
            // wall
            if (arr[x][y] || dist[x][y][z]!=-1) {
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

            // no longer available
            if (z>=k) {
                break;
            }
            if (x<1 || x>h) {
                continue;
            }
            if (y<1 || y>w) {
                continue;
            }
            // wall
            if (arr[x][y] || dist[x][y][z+1]!=-1) {
                continue;
            }
            dist[x][y][z+1]=dist[cur.first.first][cur.first.second][z]+1;
            q.push({make_pair(x,y),z+1});
        }
    }

    /*
    for (int d = 0; d<=k; ++d) {
        cout << '\n';
        for (int i = 1; i<=h; ++i) {
            for (int j = 1; j<=w; ++j) {
                cout << dist[i][j][d] << ' ';
            }
            cout << '\n';
        }
    }
    */

    vector<int> min_movement;
    for (int i = 0; i<=k; ++i) {
        if (dist[h][w][i]!=-1) {
            min_movement.push_back(dist[h][w][i]);
        }
    }
    if (min_movement.empty()) {
        cout << "-1";
    }
    else {
        sort(min_movement.begin(),min_movement.end());
        cout << min_movement.front();
    }

    return 0;
}