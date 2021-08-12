// https://www.acmicpc.net/problem/2252
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n+1);
    vector<int> indegree(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        ++indegree[v];
    }

    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (int next : adj_list[cur]) {
            --indegree[next];
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }
    for (int i : res) {
        cout << i << ' ';
    }
    
    return 0;
}