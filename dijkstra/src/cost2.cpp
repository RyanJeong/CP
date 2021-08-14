// https://www.acmicpc.net/problem/11779
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
    vector<int> p(v+1);
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
    pq.push({d[st],st});
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
                p[nxt_vtx]=vtx;
            }
        }
    }

    cout << d[en] << '\n';
    stack<int> s;
    int r = en;
    s.push(r);
    while (st!=p[r]) {
        r=p[r];
        s.push(r);
    }
    s.push(st);
    cout << s.size() << '\n';
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
