//http://icpc.me/2468
#include <bits/stdc++.h>

using namespace std;

void bfs(int, int, int);

int arr[102][102]; // 0, 1~100, OOB
int is_visited[102][102];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int min_height = 100;
    int max_height = 1;
    cin>>n;
	for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>arr[i][j];
            min_height=min(min_height,arr[i][j]);
            max_height=max(max_height,arr[i][j]);
        }
	}

    int max_area = 0;
    // min_height-1 : No area may be flooded.
    for (int h = min_height-1; h<=max_height; ++h) {
        int area = 0;
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=n; ++j) {
                if (!is_visited[i][j] && arr[i][j]>h) {
                    bfs(i,j,h);
                    ++area;
                }
            }
        }
        max_area = max(max_area,area);
        memset(is_visited,0,sizeof is_visited);
    }
    cout << max_area;

    return 0;
}

void bfs(int i, int j, int height)
{
	// right, bottom, left, top
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,-1,0,1};
	queue<pair<int, int>> q;
    q.push({i,j});
    is_visited[i][j]=true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		for (int d = 0; d<4; ++d) {
			int x = cur.first+dx[d];
			int y = cur.second+dy[d];

			if (x<1 || x>n) {
				continue;
			}
			if (y<1 || y>n) {
				continue;
			}
            if (is_visited[x][y] || arr[x][y]<=height) {
                continue;
            }
            q.push({x,y});
            is_visited[x][y]=true;
		}
	}

    return;
}