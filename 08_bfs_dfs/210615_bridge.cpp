//http://icpc.me/5014
#include <bits/stdc++.h>

using namespace std;

void dfs(int, int, int);
int bfs(int, int, int);

// right, bottom, left, top
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};

int arr[101][101];
bool is_visited[101][101];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // init.
    cin>>n;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=n; ++j) {
			cin>>arr[i][j];
		}
	}

	// devide area
	int area=1;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=n; ++j) {
			if (arr[i][j] && !is_visited[i][j]) {
				dfs(i,j,area);
				++area;
			}
		}
	}
	
	// make a bridge
	int len = 2e9;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=n; ++j) {
			if (arr[i][j] > 0) {
				continue;
			}
			for (int d = 0; d < 4; ++d) {
				int x = i+dx[d];
				int y = j+dy[d];

				if (x<1 || x>n) {
					continue;
				}
				if (y<1 || y>n) {
					continue;
				}
				if (arr[x][y] > 0) {
					memset(is_visited, 0, sizeof is_visited);
					// The bridge builded to other lands -> -1
					len = min(len,bfs(i,j,arr[x][y])-1);
					break;
				}
			}
		}
	}
	cout << len;

    return 0;
}

void dfs(int i, int j, int area)
{
	arr[i][j]=area;
	is_visited[i][j]=true;

	for (int d = 0; d<4; ++d) {
		int x = i+dx[d];
		int y = j+dy[d];

		if (x<1 || x>n) {
			continue;
		}
		if (y<1 || y>n) {
			continue;
		}
		if (!arr[x][y] || is_visited[x][y]) {
			continue;
		}
		dfs(x,y,area);
	}

	return;
}

int bfs(int i, int j, int area)
{
	queue<pair<int, int>> q;
	q.push({i,j});
	is_visited[i][j]=true;
	int step = 1;
	int size = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (arr[cur.first][cur.second]>0 && arr[cur.first][cur.second]!=area) {

			return step;
		}
		for (int d = 0; d<4; ++d) {
			int x = cur.first+dx[d];
			int y = cur.second+dy[d];
			if (x<1 || x>n) {
				continue;
			}
			if (y<1 || y>n) {
				continue;
			}
			if (is_visited[x][y]) {
				continue;
			}
			q.push({x,y});
			is_visited[x][y]=true;
		}
		if (--size==0) {
			++step;
			size=q.size();
		}
	}

	return 2e9;
}