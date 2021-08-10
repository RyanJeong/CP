// https://www.acmicpc.net/problem/11724
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

    vector<bool> is_visited(n+1);
    stack<int> s;
    int res = 0;
    for (int i = 1; i<=n; ++i) {
        if (is_visited[i]) {
            continue;
        }

        ++res;
        s.push(i);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            if (is_visited[cur]) {
                continue;
            }
            is_visited[cur]=true;

            for (int next : adj_list[cur]) {
                if (is_visited[next]) {
                    continue;
                }
                s.push(next);
            }
        }
    }
    cout << res;

    return 0;
}
