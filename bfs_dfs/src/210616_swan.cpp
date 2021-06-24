//http://icpc.me/3197
#include <bits/stdc++.h>

using namespace std;

int arr[1501][1501];
int temp[1501][1501];
int is_visited[1501][1501];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	// right, bottom, left, top
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,-1,0,1};

	int r, c;
    cin>>r>>c;
	// positions of two swans
	vector<pair<int, int>> swan;
	queue<pair<int, int>> q_water;
    for (int i = 1; i<=r; ++i) {
		string str;
		cin>>str;

		int j = 1;
		for (char c : str) {
			if (c=='.') {
				arr[i][j]=0;
				q_water.push({i,j});
			}
			else if (c=='X') {
				arr[i][j]=-1;
			}
			else if (c=='L') {
				arr[i][j]=0;
				q_water.push({i,j});
				swan.push_back({i,j});
			}
			++j;
		}
    }
	int start_x, start_y, end_x, end_y;
	start_x=swan.front().first;
	start_y=swan.front().second;
	end_x=swan.back().first;
	end_y=swan.back().second;

	// bfs
	queue<pair<int, int>> q;
	q.push({start_x,start_y});
	is_visited[start_x][start_y]=true;
	int day=0;
	do {
		// when a swan hits the ice
		queue<pair<int, int>> q_next;

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			if (end_x==cur.first && end_y==cur.second) {
				break;
			}
			for (int d = 0; d<4; ++d) {
				int x = cur.first+dx[d];
				int y = cur.second+dy[d];

				if (x<1 || x>r) {
					continue;
				}
				if (y<1 || y>c) {
					continue;
				}
				if (is_visited[x][y]) {
					continue;
				}
				if (arr[x][y]==-1) {
					q_next.push({x,y});
				}
				else {
					q.push({x,y});
				}
				is_visited[x][y]=true;
			}
		}
		// melting
		if (!is_visited[end_x][end_y]) {
			int size = q_water.size();

			while (size--) {
				auto cur = q_water.front();
				q_water.pop();

				for (int d = 0; d<4; ++d) {
					int x = cur.first+dx[d];
					int y = cur.second+dy[d];

					if (x<1 || x>r) {
						continue;
					}
					if (y<1 || y>c) {
						continue;
					}
					if (arr[x][y]==-1) {
						arr[x][y]=0;
						q_water.push({x,y});
					}
				}
			}
			q=q_next;
			++day;
		}
	} while (!is_visited[end_x][end_y]);
	cout << day;

    return 0;
}