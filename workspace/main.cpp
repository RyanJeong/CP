// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, m;
    cin>>n>>k>>m;
    vector<vector<int>> adj_list(n+1);
    for (int i = 1; i<=m; ++i) {
        vector<int> tmp(k);
        for (int j = 0; j<k; ++j) {
            cin>>tmp[j];
        }
        for (int j = 0; j<k-1; ++j) {
            for (int e = j+1; e<k; ++e) {
                adj_list[tmp[j]].push_back(tmp[e]);
                adj_list[tmp[e]].push_back(tmp[j]);
            } 
        }
    }

    queue<int> q;
    q.push(1);
    vector<int> dist(n+1);
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
            dist[next]=dist[cur]+1;
        }
    }
    cout << ((dist[n]!=-1) ? dist[n] : -1);

    return 0;
}