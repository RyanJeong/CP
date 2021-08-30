// https://www.acmicpc.net/problem/1238
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, x;
    cin>>v>>e>>x;
    //u, {cost, v};
    vector<vector<pair<int, int>>> adj_list(v+1);
    vector<vector<pair<int, int>>> adj_list_rev(v+1);
    while (e--) {
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({w,v});
        adj_list_rev[v].push_back({w,u});
    }

    // x->town
    vector<int> d(v+1, 1e9);
    d[x]=0;
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    pq.push({d[x],x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int dist = cur.first;
        int vtx = cur.second;

        if (d[vtx]!=dist) {
            continue;
        }
        for (auto nxt : adj_list[vtx]) {
            int cost = nxt.first;
            int nxt_vtx = nxt.second;
            if (d[nxt_vtx]>dist+cost) {
                d[nxt_vtx]=dist+cost;
                pq.push({d[nxt_vtx],nxt_vtx});
            }
        }
    }

    // town->x
    vector<int> d_rev(v+1, 1e9);
    d_rev[x]=0;
    pq.push({d_rev[x],x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int dist = cur.first;
        int vtx = cur.second;

        if (d_rev[vtx]!=dist) {
            continue;
        }
        for (auto nxt : adj_list_rev[vtx]) {
            int cost = nxt.first;
            int nxt_vtx = nxt.second;
            if (d_rev[nxt_vtx]>dist+cost) {
                d_rev[nxt_vtx]=dist+cost;
                pq.push({d_rev[nxt_vtx],nxt_vtx});
            }
        }
    }

    int res = 0;
    for (int i = 1; i<=v; ++i) {
        if (i==x) {
            continue;
        }
        res=max(res,d[i]+d_rev[i]);
    }
    cout << res;

    return 0;
}
