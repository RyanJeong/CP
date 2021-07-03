// https://www.acmicpc.net/problem/1966
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int m;
        cin>>m;
        queue<pair<int, int>> q; // priority, index
        vector<int> v; // priority
        for (int i = 0; i<n; ++i) {
            int p;
            cin>>p;
            v.push_back(p);
            q.push({p,i});
        }
        sort(v.begin(),v.end(),greater<int>());
        int cnt = 0;
        for (int p : v) {
            while (p!=q.front().first) {
                auto cur = q.front();
                q.pop();
                q.push(cur);
            }    
            ++cnt;
            if (m==q.front().second) {
                break;
            }
            q.pop();
        }
        cout << cnt << '\n';
    }

    return 0;
}