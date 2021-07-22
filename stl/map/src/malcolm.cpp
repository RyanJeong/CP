// https://www.acmicpc.net/problem/3078
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    map<int, vector<int>> m;
    for (int i = 0; i<n; ++i) {
        string str;
        cin>>str;
        m[str.size()].push_back(i);
    }

    long long res = 0;
    for (auto cur : m) {
        vector<int> v = cur.second;
        sort(v.begin(),v.end());
        for (int i = 0; i<v.size(); ++i) {
            // idx : 0 1 2 3 4 5
            // v[i]: 0 1 3 4 8 9
            // i: 0, v[0]: 0, k: 1, cur: (*it) 2, {0 1} (1)
            // i: 1, v[1]: 1, k: 1, cur: (*it) 2, x     (0)
            // i: 2, v[2]: 3, k: 1, cur: (*it) 4, {3 4} (1)
            // i: 3, v[3]: 4, k: 1, cur: (*it) 4, x     (0)
            // i: 4, v[4]: 8, k: 1, cur: (*it) 6, {8 9} (1)
            // -> it-i-1
            auto cur = upper_bound(v.begin(),v.end(),v[i]+k)-v.begin();
            res+=(cur-i-1);
        }
    }
    cout << res;

    return 0;
}
