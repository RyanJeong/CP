// https://www.acmicpc.net/problem/1197
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    vector<vector<pair<int, int>>> adj_list(v+1);
    for (int i = 1; i<=e; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        adj_list[a].push_back({c,b});
        adj_list[b].push_back({c,a});
    }

    // cost, u, v
    priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
    vector<bool> is_used(v+1);
    is_used[1]=true;
    for (auto next : adj_list[1]) {
        pq.push({next.first,make_pair(1,next.second)});
    }

    int cnt = 0;
    int res = 0;
    while (1) {
        auto cur = pq.top();
        pq.pop();

        int cost = cur.first;
        // int v1 = cur.second.first; // optional
        int v2 = cur.second.second;
        if (is_used[v2]) {
            continue;
        }

        is_used[v2]=true;
        res+=cost;
        ++cnt;
        if (cnt==v-1) {
            break;
        }
        for (auto next : adj_list[v2]) {
            if (!is_used[next.second]) {
                pq.push({next.first,make_pair(v2,next.second)});
            }
        }
    }
    cout << res;
    
    return 0;
}