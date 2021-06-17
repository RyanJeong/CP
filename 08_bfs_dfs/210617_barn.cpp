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

	bool is_lighted[101][101]; 
    memset(is_lighted,false,sizeof is_lighted);
    bool is_visited[101][101];
    memset(is_visited,false,sizeof is_visited);
	queue<pair<int, int>> q;
	q.push({1,1});
    is_lighted[1][1]=true;
    is_visited[1][1]=true;
	int n, m;
	cin>>n>>m;
	vector<pair<int, int>> v[101][101];
	while (m--) {
		int x, y, a, b;
		cin>>x>>y>>a>>b;
        v[x][y].push_back({a,b});
	}

	while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        for (auto to : v[cur.first][cur.second]) {
            if (is_visited[to.first][to.second]) {
                continue;
            }
            for (int d = 0; d<4; ++d) {
                int x = to.first+dx[d];
                int y = to.second+dy[d];

                if (x<1 || x>n) {
                    continue;
                }
                if (y<1 || y>n) {
                    continue;
                }
                is_lighted[to.first][to.second]=true;
                // The position 'to' is connected
                if (!is_visited[to.first][to.second] && is_visited[x][y]) {
                   is_visited[to.first][to.second]=true;
                   q.push({to.first,to.second});
                }
            }
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
            if (!is_lighted[x][y] || is_visited[x][y]) {
                continue;
            }
            is_visited[x][y]=true;
            q.push({x,y});
        }
    }

    int room = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            room+=is_lighted[i][j];
        }
    }
    cout << room;

    return 0;
}