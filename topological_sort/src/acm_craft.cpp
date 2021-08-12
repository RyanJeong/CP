// https://www.acmicpc.net/problem/1005
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<int> d(n+1);
        vector<int> dp(n+1);
        for (int i = 1; i<=n; ++i) {
            cin>>d[i];
            dp[i]=d[i];
        }
        vector<vector<int>> adj_list(n+1);
        vector<int> indegree(n+1);
        for (int i = 1; i<=k; ++i) {
            int u, v;
            cin>>u>>v;
            adj_list[u].push_back(v);
            ++indegree[v];
        }
        int w;
        cin>>w;

        queue<int> q;
        for (int i = 1; i<=n; ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur==w) {
                break;
            }

            for (int next : adj_list[cur]) {
                dp[next]=max(dp[next],dp[cur]+d[next]);
                --indegree[next];
                if (!indegree[next]) {
                    q.push(next);
                }
            }
        }
        cout << dp[w] << '\n';
    }
    
    return 0;
}
