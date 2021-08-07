// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    vector<int> areas;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (is_visited[i][j] || !v[i][j]) {
                continue;
            }

            int area = 0;
            stack<pair<int, int>> s;
            s.push({i,j});
            is_visited[i][j]=true;
            while (!s.empty()) {
                ++area;
                auto cur = s.top();
                s.pop();

                const vector<pair<int, int>> adjacency = {
                    {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
                };
                for (auto d : adjacency) {
                    int x = cur.first+d.first;
                    int y = cur.second+d.second;

                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (is_visited[x][y] || !v[x][y]) {
                        continue;
                    }
                    s.push({x,y});
                    is_visited[x][y]=true;
                }
            }
            areas.push_back(area);
        }
    }
    sort(areas.begin(),areas.end());
    cout << areas.size()  << '\n' << ((!areas.empty()) ? areas.back() : 0);

    return 0;
}
