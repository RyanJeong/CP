// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<bool> is_visited;

void dfs(int cur);
void bfs(int v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, v;
    cin>>n>>m>>v;
    adj_list=vector<vector<int>>(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 1; i<=n; ++i) {
        sort(adj_list[i].begin(),adj_list[i].end());
    }
    
    is_visited=vector<bool>(n+1);
    dfs(v);
    cout << '\n';
    is_visited=vector<bool>(n+1);
    bfs(v);

    return 0;
}

void dfs(int cur)
{
    is_visited[cur]=true;
    cout << cur << ' ';
    for (int next : adj_list[cur]) {
        if (is_visited[next]) {
            continue;
        }
        dfs(next);
    }

    return;
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    is_visited[v]=true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : adj_list[cur]) {
            if (is_visited[next]) {
                continue;
            }
            q.push(next);
            is_visited[next]=true;
        }
    }

    return;
}
