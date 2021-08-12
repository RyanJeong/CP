// https://www.acmicpc.net/problem/11725
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> parent;

void dfs(int cur);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    adj_list=vector<vector<int>>(n+1);
    parent=vector<int>(n+1);
    for (int i = 1; i<n; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i<=n; ++i) { // E = V-1
        cout << parent[i] << '\n';
    }
    
    return 0;
}

void dfs(int cur)
{
    for (int next : adj_list[cur]) {
        if (parent[cur]==next) {
            continue;
        }
        parent[next]=cur;
        dfs(next);
    }

    return;
}