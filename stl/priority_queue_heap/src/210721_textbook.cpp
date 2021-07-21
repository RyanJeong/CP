// https://www.acmicpc.net/problem/1766
// 선행조건이 남아있다면 cnt_lock은 참
// 선행조건이 모두 종료됐다면 cnt_lock은 거짓
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    int m;
    cin>>m;
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt_lock[n+1];
    memset(cnt_lock,0,sizeof cnt_lock);
    vector<int> v[n+1];
    while (m--) {
        int s;
        cin>>s;
        int t;
        cin>>t;
        v[s].push_back(t);
        ++cnt_lock[t];
    }

    for (int i = 1; i<=n; ++i) {
        if (cnt_lock[i]) {
            continue;
        }
        pq.push(i);
    }
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        cout << cur << ' ';
        for (int i : v[cur]) {
            --cnt_lock[i];
            if (!cnt_lock[i]) {
                pq.push(i);
            }
        }
    }

    return 0;
}