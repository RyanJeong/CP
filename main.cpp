// https://www.acmicpc.net/problem/14442
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	static int dist[1001][1001][10]; // 0, 1 ~ 1000, OOB, cnt(0~k-1)
	static string arr[1001];
	int n, m, k;
    cin>>n>>m>>k;
    for (int i = 1; i<=n; ++i) {
        cin>>(arr[i].begin()+1);
    }

    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,-1,0,1};
    queue<pair<pair<int, int>, int>> q;
    q.push({make_pair(1,1),0}); // {x,y}, cnt_wall_removed
    dist[1][1][0]=1;
	int res = 0;
	bool is_possible = false;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first.first;
        int cur_y = cur.first.second;
        int cnt = cur.second;

        if (cur_x==n && cur_y==m) {
			res=dist[cur_x][cur_y][cnt];	
			is_possible=true;
			break;
        }
        for (int d = 0; d<4; ++d) {
            int x = cur_x+dx[d];
            int y = cur_y+dy[d];

            if (x<1 || x>n) {
                continue;
            }
            if (y<1 || y>m) {
                continue;
            }
            if (dist[x][y][cnt]) {
                continue;
            }
            if (arr[x][y]=='0') {
                dist[x][y][cnt]=dist[cur_x][cur_y][cnt]+1;
                q.push({make_pair(x,y),cnt});
				cout << cur_x << ' ' << cur_y << ' ' << cnt << '>'
				<< x << ' ' << y << ' ' << cnt << '\n';
            }
            if (arr[x][y]=='1' && cnt<k) { // wall exists on the position
                dist[x][y][cnt+1]=dist[cur_x][cur_y][cnt]+1;
                q.push({make_pair(x,y),cnt+1});
				cout << cur_x << ' ' << cur_y << ' ' << cnt << '>'
				<< x << ' ' << y << ' ' << cnt+1 << '\n';
            }
        }
    }
	cout << ((is_possible) ? res : -1);

    return 0;
}