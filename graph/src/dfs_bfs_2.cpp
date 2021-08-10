// https://www.acmicpc.net/problem/11724
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, v;
    cin>>n>>m>>v;
    vector<vector<int>> adj_list(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for (int i = 1; i<=n; ++i) {
        sort(adj_list[i].begin(),adj_list[i].end());
    }

    // DFS
    vector<bool> is_visited(n+1);
    stack<int> s;
    s.push(v);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (is_visited[cur]) {
            continue;
        }
        is_visited[cur]=true;
        cout << cur << ' ';

        // 순서에 주의
        stack<int> tmp;
        for (int next : adj_list[cur]) {
            if (is_visited[next]) {
                continue;
            }
            tmp.push(next);
        }
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }
    cout << '\n';

    // BFS
    fill(is_visited.begin(),is_visited.end(),false);
    queue<int> q;
    q.push(v);
    is_visited[v]=true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for (int next : adj_list[cur]) {
            if (is_visited[next]) {
                continue;
            }
            q.push(next);
            is_visited[next]=true;
        }
    }

    return 0;
}