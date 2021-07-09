// https://www.acmicpc.net/problem/16946
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<bool>> is_visited;
    vector<vector<char>> arr;
	int n, m;
    cin>>n>>m;
    is_visited=vector<vector<bool>>(n+1,vector<bool>(m+1,false));
    arr=vector<vector<char>>(n+1,vector<char>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>arr[i][j];
        }
    }

    const int dx[] = {1,0,-1,0};
    const int dy[] = {0,-1,0,1};
    vector<vector<int>> area_map(n+1,vector<int>(m+1,-1));
    vector<int> area_size;
    int area = 0;
    queue<pair<int, int>> q;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (arr[i][j]=='0' && !is_visited[i][j]) {
                is_visited[i][j]=true;
                q.push({i,j});
                area_map[i][j]=area;
                int size = 0;
                while (!q.empty()) {
                    auto cur = q.front();
                    q.pop();

                    ++size;
                    for (int d = 0; d<4; ++d) {
                        int x = cur.first+dx[d];
                        int y = cur.second+dy[d];
                    
                        if (x<1 || x>n) {
                            continue;
                        }
                        if (y<1 || y>m) {
                            continue;
                        }
                        if (arr[x][y]!='0' || is_visited[x][y]) {
                            continue;
                        }
                        is_visited[x][y]=true;
                        q.push({x,y});
                        area_map[x][y]=area;
                    }
                }
                area_size.push_back(size);
				++area;
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (arr[i][j]=='1') {
                set<int> s; // remove dup. cases

                for (int d = 0; d<4; ++d) {
                    int x = i+dx[d];
                    int y = j+dy[d];
                
                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (area_map[x][y]==-1) {
                        continue;
                    }
                    s.insert(area_map[x][y]);
                }
                int cnt = 1;
                for (int area : s) {
                    cnt += area_size[area];
                }
				cnt%=10;
                arr[i][j]=cnt+'0';
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }

    return 0;
}