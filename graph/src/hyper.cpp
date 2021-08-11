// https://www.acmicpc.net/problem/5214
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, m;
    cin>>n>>k>>m;
    vector<vector<int>> adj_list(n+m+1);
    for (int i = 1; i<=m; ++i) {
        for (int j = 1; j<=k; ++j) {
            int tmp;
            cin>>tmp;

            adj_list[i+n].push_back(tmp); // dummy station
            adj_list[tmp].push_back(i+n);
        }
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+m+1);
    fill(dist.begin(),dist.end(),0);
    dist[1]=1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj_list[cur]) {
            if (dist[next]) {
                continue;
            }
            q.push(next);
            if (next>n) {
                dist[next]=dist[cur]; // dummy station
            }
            else {
                dist[next]=dist[cur]+1;
            }
        }
    }
    cout << ((dist[n]) ? dist[n] : -1);

    return 0;
}
