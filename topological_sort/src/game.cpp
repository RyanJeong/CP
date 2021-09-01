// https://www.acmicpc.net/problem/1516
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    vector<int> d(n+1);
    vector<int> dp(n+1);
    vector<vector<int>> adj_list(n+1);
    vector<int> indegree(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>d[i];
        dp[i]=d[i];
        while (1) {
            int tmp;
            cin>>tmp;
            if (tmp==-1) {
                break;
            }
            adj_list[tmp].push_back(i);
            ++indegree[i];
        }
    }

    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : adj_list[cur]) {
            dp[next]=max(dp[next],dp[cur]+d[next]);
            --indegree[next];
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }

    for (int i = 1; i<=n; ++i) {
        cout << dp[i] << '\n';
    }
    
    return 0;
}
