//http://icpc.me/2206
#include <bits/stdc++.h>

using namespace std;

int bfs(void);

// {x,y,type}
int dist[1002][1002][2]; // 0, 1 ~ 1000, OOB, type(0: before, 1: after)
char arr[1002][1002];
int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // init.
    cin>>n>>m;
	for (int i = 1; i<=n; ++i) {
        string str;
        cin>>str;

        int j = 1;
        for (char c : str) {
            arr[i][j]=c;
            ++j;
        }
	}
    cout << bfs();

    return 0;
}

int bfs(void)
{
	// right, bottom, left, top
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,-1,0,1};
	queue<pair<pair<int, int>, int>> q;
	q.push({make_pair(1,1),0});
    dist[1][1][0]=1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
        int cur_x = cur.first.first;
        int cur_y = cur.first.second;
        int type = cur.second;

        if (cur_x==n && cur_y==m) {

            return dist[cur_x][cur_y][type];
        }
		for (int d = 0; d<4; ++d) {
			int x = cur_x+dx[d];
			int y = cur_y+dy[d];

			if (x<1 || x>n) {
				continue;
			}
			if (y<1 || y>m) {
				continue;
			}
            if (dist[x][y][type]) {
                continue;
            }
            if (arr[x][y]=='0') {
                dist[x][y][type]=dist[cur_x][cur_y][type]+1;
                q.push({make_pair(x,y),type});
            }
            else if (arr[x][y]=='1' && !type) { // wall exists on the position
                dist[x][y][1]=dist[cur_x][cur_y][type]+1;
                q.push({make_pair(x,y),1});
            }
		}
	}

    return -1;
}