// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int dfs(int, int);

vector<vector<int>> v;
vector<vector<bool>> is_visited;
vector<int> areas;
int n, m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    v=vector<vector<int>>(n+1,vector<int>(m+1));
    is_visited=vector<vector<bool>>(n+1,vector<bool>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (is_visited[i][j] || !v[i][j]) {
                continue;
            }

            areas.push_back(dfs(i,j));
        }
    }
    sort(areas.begin(),areas.end());
    cout << areas.size()  << '\n' << ((!areas.empty()) ? areas.back() : 0);

    return 0;
}

int dfs(int i, int j)
{
    int area = 1;
    is_visited[i][j]=true;
    
    const vector<pair<int, int>> adjacency = {
        {1,0},{0,1},{-1,0},{0,-1} // horizontally, vertically
    };
    for (auto d : adjacency) {
        int x = i+d.first;
        int y = j+d.second;

        if (x<1 || x>n) {
            continue;
        }
        if (y<1 || y>m) {
            continue;
        }
        if (is_visited[x][y] || !v[x][y]) {
            continue;
        }
        area+=dfs(x,y);
    }

    return area;
}
