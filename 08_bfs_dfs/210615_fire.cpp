//http://icpc.me/5427
#include <bits/stdc++.h>

using namespace std;

string arr[1001];       // #: wall, .: path, @: entry point, *: fire
int    man[1001][1001]; // 0: not visited, 1: visited
int    fire[1001][1001];

// right -> bottom -> left -> top
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; 

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin>>t;
	
	while (t--) {
		int r, c;
		// NOTICE: entered width(c) before height(r)
		cin>>c>>r;
		queue<pair<int, int>> q_man, q_fire;

		for (int i = 0; i<r; ++i) {
			cin>>arr[i]; 

			for (int j = 0; j<c; ++j) {
				if (arr[i][j]=='*') {
					q_fire.push({i,j});
					fire[i][j]=1;
				} 
				else if (arr[i][j]=='@') {
					q_man.push({i,j});
					man[i][j]=1;
				}
			}
		}
		while (!q_fire.empty()) {
			auto cur = q_fire.front();
			q_fire.pop();

			for (int d = 0; d<4; ++d) {
				int x = cur.first+dx[d];
				int y = cur.second+dy[d];

				if (x<0 || x>=r) {
					continue;
				}
				if (y<0 || y>=c) {
					continue;
				}
				if (fire[x][y] || arr[x][y]=='#') {
					continue;
				}
				fire[x][y]=fire[cur.first][cur.second]+1;
				q_fire.push({x,y});
			}
		}

		int sec = 0;
		while (!q_man.empty() && !sec) {
			auto cur = q_man.front();
			q_man.pop();

			for (int d = 0; d<4; ++d) {
				int x = cur.first+dx[d];
				int y = cur.second+dy[d];

				if (x<0 || x>=r || y<0 || y>=c) {
					sec=man[cur.first][cur.second];
					break;
				}
				// There will be exactly one ‘@’ in the map
				// Already man[x][y] value is shortest
				if (man[x][y] || arr[x][y]=='#') {
					continue;
				}
				// +1: man's movement
				if (fire[x][y] && fire[x][y] <= man[cur.first][cur.second]+1) { // fire has broke out && fire spread before a man ran away.
					continue;
				}
				man[x][y] = man[cur.first][cur.second]+1;
				q_man.push({x,y});
			}
		}
		if (sec) {
			cout << sec << '\n';
		}
		else {
			cout << "IMPOSSIBLE" << '\n';
		}
		memset(man, 0, sizeof man);
		memset(fire, 0, sizeof fire);
	}

    return 0;
}