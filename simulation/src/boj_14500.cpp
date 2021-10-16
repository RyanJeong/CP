// https://www.acmicpc.net/problem/14500
#include <bits/stdc++.h>

using namespace std;

int dfs(int i, int j, int cnt);
int get_shape_sum(int i, int j);

int n, m;
vector<vector<int>> v;
vector<vector<bool>> is_visited;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    v=vector<vector<int>>(n+1,vector<int>(m+1)); // 1-based;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    is_visited=vector<vector<bool>>(n+1,vector<bool>(m+1));
    int res = 0;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            is_visited[i][j]=true;
            res=max(res,dfs(i,j,1));
            res=max(res,get_shape_sum(i,j));
            is_visited[i][j]=false;
        }
    }
    cout << res;

    return 0;
}

int dfs(int i, int j, int cnt)
{
    if (cnt==4) {

        return v[i][j];
    }

    int sum = 0;
    const vector<pair<int, int>> adjacency = {
        {0,1},{-1,0},{0,-1},{1,0}
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
        if (is_visited[x][y]) {
            continue;
        }
        is_visited[x][y]=true;
        sum=max(sum,v[i][j]+dfs(x,y,cnt+1));
        is_visited[x][y]=false;
    }

    return sum;
}

int get_shape_sum(int i, int j) // ㅗ
{
    int sum = 0;

    if (i>1 && j>1 && j<m) { // ㅗ, 'center', up,  left,  right
        sum=max(sum,v[i][j]+v[i-1][j]+v[i][j-1]+v[i][j+1]);
    }
    if (i>1 && j<m && i<n) { // ㅏ 'center', up,   right, bottom
        sum=max(sum,v[i][j]+v[i-1][j]+v[i][j+1]+v[i+1][j]);
    }
    if (j>1 && j<m && i<n) { // ㅜ 'center', left, right, bottom
        sum=max(sum,v[i][j]+v[i][j-1]+v[i][j+1]+v[i+1][j]);
    }
    if (i>1 && j>1 && i<n) { // ㅓ 'center', up,   left,  bottom
        sum=max(sum,v[i][j]+v[i-1][j]+v[i][j-1]+v[i+1][j]);
    }

    return sum;
}
