// https://www.acmicpc.net/problem/12015
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    vector<int> lis;
    lis.push_back(v[1]);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
        }
    }
    cout << lis.size();

    return 0;
}