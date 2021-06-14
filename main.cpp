//http://icpc.me/2206
#include <bits/stdc++.h>

using namespace std;

void bfs(void);

// {x,y}
int arr[101][101]; // 0, 1 ~ 100

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
	queue<pair<int, int>> wall;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			int temp;
			cin>>temp;
			if (temp==1) {
				arr[i][j]=-1;
				q.push({i,j});
			}
			else {
				arr[i][j]=0;
			}
		}
	}
	int arr_temp[101][101];
	memcpy(arr_temp, arr, sizeof arr); // backup
	vector<int> path;
	while (!wall.empty()) {
		auto cur = wall.front();
		wall.pop();
		arr[i][j]=0;
		bfs();
		if (arr[i][j]) {
			path.push_back(res);
		}
		min_path = min(min_path, path);
		memcpy(arr, arr_temp, sizeof arr); // restore
	}
	sort(path.begin(),path.end());
	int min = (path.empty()) ? -1 : path.front();
	cout << min;

	return 0;
}
	
void bfs(void)
{
	// right, bottom, left, top
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
	queue<pair<int, int>> q;
	q.push({1,1});
	arr[1][1]=1;

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
			if (arr[x][y] && arr[x][y] < arr[cur.first][cur.second]+1) {
				continue;
			}
			arr[x][y] = arr[cur.first][cur.second]+1;
			q.push({x,y});
		}
	}

	return;
}