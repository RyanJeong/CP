//http://icpc.me/7562
#include <bits/stdc++.h>

using namespace std;

void bfs(int, int, int);

// { x, y }
char arr[100][100]; // count of movement
bool is_visited[100][100];	// 0: not yet, 1: visited
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	// case
	cin>>n;
	queue<pair<int, int>> q;
	for (int i = 0; i<n; ++i) {
		string str;
		cin>>str;

		for (int j = 0; j<n; ++j) {
			arr[i][j]=str[j];
			// treat 'B' first
			if (str[j]=='B') {
				q.push({i,j});
			}
		}
	}
	// treat 'B'
	int n_rgb = 0;

	while (!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;

		q.pop();
		if (!is_visited[i][j]) {
			bfs(i,j,BLUE);
			++n_rgb;
		}
	}

	//treat 'R'
	int n_rb = n_rgb;
	bool is_visited_temp[100][100];
	memcpy(is_visited_temp, is_visited, sizeof is_visited);

	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (!is_visited[i][j] && arr[i][j]=='R') {
				bfs(i,j,RED);
				++n_rgb;
			}
		}
	}

	//treat 'G'
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (!is_visited[i][j] && arr[i][j]=='G') {
				bfs(i,j,GREEN);
				++n_rgb;
			}
		}
	}

	//treat "RG"
	memcpy(is_visited, is_visited_temp, sizeof is_visited);
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (!is_visited[i][j]) {
				bfs(i,j,RED_GREEN);
				++n_rb;
			}
		}
	}
	cout << n_rgb << ' ' << n_rb;

	return 0;
}

void bfs(int i, int j, int type)
{
	// right, bottom, left, top
	int dx[4] = {1,0,-1,0};
	int dy[4] = {0,-1,0,1};
	queue<pair<int, int>> q;
	q.push({i,j});
	is_visited[i][j]=true;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int d = 0; d<4; ++d) {
			int x = cur.first+dx[d];
			int y = cur.second+dy[d];

			if (x<0 || x>=n) {
				continue;
			}
			if (y<0 || y>=n) {
				continue;
			}
			if (is_visited[x][y]) {
				continue;
			}
			switch (type) {
			case RED:
				if (arr[x][y]!='R') {
					continue;
				}
				break;
			case GREEN:
				if (arr[x][y]!='G') {
					continue;
				}
				break;
			case BLUE:
				if (arr[x][y]!='B') {
					continue;
				}
				break;
			case RED_GREEN:
				if (arr[x][y]=='B') {
					continue;
				}
				break;
			default:
				break;
			}
			is_visited[x][y]=true;
			q.push({x,y});
		}
	}

	return;
}