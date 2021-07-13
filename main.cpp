// https://www.acmicpc.net/problem/16920
// https://codeforces.com/contest/1105/problem/D
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, p;
    cin>>n>>m>>p;
    static int movement[10];
    for (int i = 1; i<=p; ++i) {
        cin>>movement[i];
    }
    static char arr[1001][1001];
    vector<pair<int, int>> v[p+1];
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
			char& c = arr[i][j];
			cin>>c;
			if (isdigit(c)) {
				c-='0';
				v[(int) c].push_back({i,j});
			}
        }
        cin.ignore();
    }

	static int turn[1001][1001];
	for (int i = 1; i<=p; ++i) {
		const int dx[] = {1,0,-1,0};
		const int dy[] = {0,-1,0,1};
		int mv = movement[i];
		queue<pair<int, int>> q;
		while (!v[i].empty()) {
			auto cur = v[i].back();
			v[i].pop_back();
			q.push({cur.first,cur.second});
			turn[cur.first][cur.second]=1;
			arr[cur.first][cur.second]=i;
		}
        int t = 1;
		for (int j = 1; !q.empty(); ++j) {
			int cnt = q.size();
			while (cnt--) {
				auto cur = q.front();
				q.pop();

				for (int d = 0; d<4; ++d) {
					int x = cur.first+dx[d];
					int y = cur.second+dy[d];

					if (x<1 || x>n) {
						continue;
					}
					if (y<1 || y>m) {
						continue;
					}
					if (arr[x][y]==i || arr[x][y]=='#') {
						continue;
					}
					if (arr[x][y]!='.' && turn[x][y]<=t) {
						continue;
					}
					q.push({x,y});
					turn[x][y]=t;
					arr[x][y]=i;
				}
			}
            // 1 2 3 4 5 ...
            // 1 1 2 2 3 ...
            // 1 1 1 2 2 ...
            t+=((j%mv) ? 0 : 1);
		}
	}
	static int freq[10];
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			++freq[(int) arr[i][j]];
		}
	}
	for (int i = 1; i<=p; ++i) {
		cout << freq[i] << ' ';
	}

    return 0;
}