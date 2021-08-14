// https://www.acmicpc.net/problem/1916
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    //u, {cost, v};
    vector<vector<pair<int, int>>> adj_list(v+1);
    while (e--) {
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({w,v});
    }
    int st, en;
    cin>>st>>en;

    // cost, v
    vector<int> d(v+1, 1e9);
    d[st]=0;
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    pq.push({d[st],st});
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
    cout << d[en] << '\n';

    return 0;
}