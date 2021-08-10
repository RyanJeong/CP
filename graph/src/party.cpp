// Olympiad > Japanese Olympiad in Informatics 
// > Japanese Olympiad in Informatics Qualification Round > JOI 2010 예선 3번

// https://www.acmicpc.net/problem/5567
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

    if (!adj_list[1].size()) {
        cout << 0;

        return 0;
    }
    queue<int> q;
    vector<bool> is_visited(n+1);
    q.push(1);
    is_visited[1]=true;
    int res = 0;
    int step = 2;
    while (step-- && !q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            int cur = q.front();
            q.pop();

            for (int next : adj_list[cur]) {
                if (is_visited[next]) {
                    continue;
                }
                ++res;
                q.push(next);
                is_visited[next]=true;
            }
        }
    }
    cout << res;

    return 0;
}
