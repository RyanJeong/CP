// https://www.acmicpc.net/problem/6118
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+1);
    fill(dist.begin()+1,dist.end(),-1); // init.
    dist[1]=0;
    int res = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj_list[cur]) {
            if (dist[next]!=-1) {
                continue;
            }
            q.push(next);
            dist[next]=dist[cur]+1;
            res=max(res,dist[next]);
        }
    }

    int idx = 0;
    int cnt = 0;
    for (int i = 1; i<=n; ++i) {
        if (res==dist[i]) {
            ++cnt;
            if (!idx) {
                idx=i;
            }
        }
    }
    cout << idx << ' ' << res << ' ' << cnt;

    return 0;
}
