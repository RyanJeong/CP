// https://www.acmicpc.net/problem/2109
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> v;
    while (n--) {
        int p, d;
        cin>>p>>d;
        v.push_back({d,p});
    }
    sort(v.begin(),v.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto cur : v) {
        pq.push(cur.second);
        if (pq.size()>cur.first) {
            pq.pop();
        }
    }
    int res = 0;
    while (!pq.empty()) {
        res+=pq.top();
        pq.pop();
    }
    cout << res;

    return 0;
}