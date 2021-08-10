// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

void dfs(int cur);

vector<bool> is_visited;
vector<vector<int>> adj_list;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    adj_list=vector<vector<int>>(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    is_visited=vector<bool>(n+1);
    int res = 0;
    for (int i = 1; i<=n; ++i) {
        if (is_visited[i]) {
            continue;
        }
        
        ++res;
        is_visited[i]=true;
        dfs(i);
    }
    cout << res;

    return 0;
}

void dfs(int cur)
{
    for (int next : adj_list[cur]) {
        if (is_visited[next]) {
            continue;
        }
        is_visited[next]=true;
        dfs(next);
    }

    return;
}
