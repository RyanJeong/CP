//http://icpc.me/11967
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	// right, botq_tom, left, top
	const int dx[4] = {1,0,-1,0};
	const int dy[4] = {0,-1,0,1};

	int arr[101][101]; // 1 ~ n
	// -1: no light, 0: visited, 1: light
	memset(arr,-1,sizeof arr);
	arr[1][1] = 1;
	int n, m;
	cin>>n>>m;
	queue<pair<int, int>> q;
	q.push({1,1});
	arr[1][1]=0;
	vector<pair<pair<int, int>, pair<int, int>>> v;
	while (m--) {
		int x, y, a, b;
		cin>>x>>y>>a>>b;
		v.push_back({make_pair(x,y),make_pair(a,b)});
	}

	int room = 1;
	while (!q.empty()) {
		for (auto l : v) {
			if (arr[l.first.first][l.first.second]!=-1) {
				for (int d = 0; d<4; ++d) {
					int x = l.first.first+dx[d];
					int y = l.first.second+dy[d];

					if (arr[x][y]==0) {
						q.push({x,y});
						break;
					}
				}
			}
		}
	}

/*
	int room = 0;
	do {
		int size=l.size();

		for (auto iter = l.begin(); iter!=l.end(); ++iter) {
			auto it = *iter;
			auto from = it.first;
			auto to = it.second;

			if (arr[from.first][from.second]!=-1) {
				for (int d = 0; d<4; ++d) {
					int x = to.first+dx[d];
					int y = to.second+dy[d];

					if (x<1 || x>n) {
						continue;
					}
					if (y<1 || y>n) {
						continue;
					}
					if (arr[x][y]==-1) {
						continue;
					}
					if (arr[to.first][to.second]==-1) {
						arr[to.first][to.second]=1;
						++room;
					}
					else {
						arr[to.first][to.second]=0;
					}
					iter = l.erase(iter);
				}
			}
		}
		if (size==l.size()) {
			break;
		}
	} while (!l.empty());
	cout << room;
	*/

	return 0;
}