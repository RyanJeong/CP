// https://www.acmicpc.net/problem/2644
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int st, en;
    cin>>st>>en;
    int m;
    cin>>m;
    vector<vector<int>> adj_list(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    queue<int> q;
    q.push(st);
    vector<int> dist(n+1);
    fill(dist.begin()+1,dist.end(),-1); // init.
    dist[st]=0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj_list[cur]) {
            if (dist[next]!=-1) {
                continue;
            }
            q.push(next);
            dist[next]=dist[cur]+1;
        }
    }
    cout << dist[en];

    return 0;
}
