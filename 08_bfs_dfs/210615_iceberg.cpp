//http://icpc.me/2468
#include <bits/stdc++.h>

using namespace std;

void bfs(int, int);
void melt(void);

int arr[302][302]; // 0, 1~300, OOB
int temp[302][302]; 
int is_visited[302][302];
int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>arr[i][j];
        }
    }

    int year = 0;
    int area;
    do {
        area=0;
        for (int i = 1; i<=n; ++i) {
            for (int j = 1; j<=m; ++j) {
                if (arr[i][j] && !is_visited[i][j]) {
                    // cout << "i: " << i << ", j: " << j << '\n';
                    bfs(i,j);
                    ++area;
                }
            }
        }
        if (area>1) {
            break;
        }
        else {
            memset(is_visited,0,sizeof is_visited);
            melt();
            ++year;
        }        
        // cout << "area: " << area << ", year: " << year << '\n';
    } while (area);
    cout << ((!area) ? 0 : year);

    return 0;
}

void bfs(int i, int j)
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
			if (y<1 || y>m) {
				continue;
			}
            if (is_visited[x][y] || !arr[x][y]) {
                continue;
            }
            q.push({x,y});
            is_visited[x][y]=true;
		}
	}

    return;
}

void melt(void)
{
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            temp[i][j]=arr[i][j];
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (arr[i][j]) {
                // left
                int level = 0;

                if (i-1>=1 && !temp[i-1][j]) {
                    ++level;
                }
                // bottom
                if (j+1<=m && !temp[i][j+1]) {
                    ++level;
                }
                // right
                if (i+1<=n && !temp[i+1][j]) {
                    ++level;
                }
                // top
                if (j-1>=1 && !temp[i][j-1]) {
                    ++level;
                }
                arr[i][j] = max(temp[i][j]-level,0);
            }
        }
    }

    return;
}