// https://www.acmicpc.net/problem/2623
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n+1);
    vector<int> indegree(n+1);
    for (int i = 1; i<=m; ++i) {
        int t;
        cin>>t;
        vector<int> tmp(t);
        for (int j = 0; j<t; ++j) {
            cin>>tmp[j];
        }
        for (int j = 1; j<t; ++j) {
            adj_list[tmp[j-1]].push_back(tmp[j]);
            ++indegree[tmp[j]];
        }
    }

    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (int next : adj_list[cur]) {
            --indegree[next];
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }
    if (res.size()==n) {
        for (int i : res) {
            cout << i << '\n';
        }
    }
    else {
        cout << 0;
    }
    
    return 0;
}
