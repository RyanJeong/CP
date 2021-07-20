#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> v(1); // 1-based
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        int a, b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());
    vector<int> lis; // 0-based
    lis.push_back(v[1].second); 
    vector<int> len(1); // 1-based
    len.push_back(1);
    for (int i = 2; i<=n; ++i) {
        if (v[i].second>lis.back()) {
            lis.push_back(v[i].second);
            len.push_back(lis.size());
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i].second);
            lis[cur-lis.begin()]=v[i].second;
            len.push_back(cur-lis.begin()+1); // 0-based
        }
    }
    int target = lis.size();
    cout << n-target << '\n';
    stack<int> s;
    for (int i = n; i>0; --i) {
        if (len[i]==target) {
            s.push(v[i].second);
            --target;
        }
    }
    while (!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }

    return 0;
}