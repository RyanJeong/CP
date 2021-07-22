// https://www.acmicpc.net/problem/3340
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n;
    cin>>c>>n;
    vector<int> v(n); // 0-based
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    reverse(v.begin(),v.end());
    set<int> s;
    vector<int> res;
    for (int i : v) {
        if (s.find(i)==s.end()) {
            s.insert(i);
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    while (!res.empty()) {
        cout << res.back() << ' ';
        res.pop_back();
    }

    return 0;
}