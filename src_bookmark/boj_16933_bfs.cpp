// https://www.acmicpc.net/problem/16933
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 0, 1 ~ 1000, OOB, cnt(0~k-1)
	static bool is_visited[1001][1001][10]; 
	static string arr[1001];
	int n, m, k;
    cin>>n>>m>>k;
    for (int i = 1; i<=n; ++i) {
        cin>>(arr[i]);
        arr[i].insert(arr[i].begin(),'0');
    }

    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,-1,0,1};
    queue<pair<pair<int, int>, pair<int, int>>> q;
    // {x,y}, {dist, cnt_wall_removed}
    q.push({make_pair(1,1),make_pair(1,0)}); 
	int res = -1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int cur_x = cur.first.first;
        int cur_y = cur.first.second;
        int dist = cur.second.first;
        int cnt = cur.second.second;

        if (cur_x==n && cur_y==m) {
			res=dist;
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
            if (!is_visited[x][y][cnt] && arr[x][y]=='0') {
                q.push({make_pair(x,y),make_pair(dist+1,cnt)});
                is_visited[x][y][cnt]=true;
            }
            // a wall exists on the position
            if (!is_visited[x][y][cnt+1] && arr[x][y]=='1' && cnt<k) { 
                // afternoon
                if (dist%2) {
                    q.push({make_pair(x,y),make_pair(dist+1,cnt+1)});
                    is_visited[x][y][cnt+1]=true;
                } 
                // evening
                else {
                    q.push({make_pair(cur_x,cur_y),make_pair(dist+1,cnt)});
                }
            }
        }
    }
	cout << res;

    return 0;
}