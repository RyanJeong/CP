// https://www.acmicpc.net/problem/1238
#include <bits/stdc++.h>

using namespace std;

void dijkstra(vector<int>& d, int v, int start);

vector<vector<pair<int, int>>> adj_list;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, x;
    cin>>v>>e>>x;
    //u, {cost, v};
    adj_list=vector<vector<pair<int, int>>>(v+1);
    for (int i = 1; i<=e; ++i) {
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({w,v});
    }

    // x->town
    vector<int> d;
    dijkstra(d,v,x);
    int res = 0;
    for (int i = 1; i<=v; ++i) {
        if (i==x) {
            continue;
        }

        // town->x
        vector<int> tmp;
        dijkstra(tmp,v,i);
        res=max(res,d[i]+tmp[x]);
    }
    cout << res;

    return 0;
}

void dijkstra(vector<int>& d, int v, int start)
{
    d=vector<int>(v+1, 1e9);
    d[start]=0;
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    // cost, v
    pq.push({d[start],start});
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

    return;
}
