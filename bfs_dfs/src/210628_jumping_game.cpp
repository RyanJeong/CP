// https://www.acmicpc.net/problem/15558
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<vector<char>> v(2+1,vector<char>(n+1));
    vector<vector<bool>> is_visited(2+1,vector<bool>(n+1));
    for (int i = 1; i<=2; ++i) {
        for (int j = 1; j<=n; ++j) {
            cin>>v[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({1,1});
    is_visited[1][1]=true;
    int time = 1;
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            auto cur = q.front();
            q.pop();

            const vector<pair<int, int>> jump_to = {{1,1},{1,-1},{2,k}};
            for (auto d : jump_to) {
                int x = (cur.first+d.first)%2+1; // 1->2, 2->1
                int y = cur.second+d.second;
                
                if (y>n) {
                    cout << 1;

                    return 0;
                }
                if (y<1 || time>=y) {
                    continue;
                }
                if (v[x][y]=='0' || is_visited[x][y]) {
                    continue;
                }
                q.push({x,y});
                is_visited[x][y]=true;
            }
        }
        ++time;
    }
    cout << 0;

    return 0;
}
