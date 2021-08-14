// https://www.acmicpc.net/problem/1753
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    int start;
    cin>>start;
    //u, {cost, v};
    vector<vector<pair<int, int>>> adj_list(v+1);
    while (e--) {
        int u, v, w;
        cin>>u>>v>>w;
        adj_list[u].push_back({w,v});
    }

    // cost, v
    vector<int> d(v+1, 1e9);
    d[start]=0;
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    pq.push({d[start],start});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int dist = cur.first;
        int vtx = cur.second;

        // 예전 정보는 무시
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

    for (int i = 1; i<=v; ++i) {
        if (d[i]==1e9) {
            cout << "INF";
        }
        else {
            cout << d[i];
        }
        cout << '\n';
    }

    return 0;
}