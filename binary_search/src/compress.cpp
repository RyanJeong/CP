// https://www.acmicpc.net/problem/18870
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];    
    }

    vector<int> tmp(v);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for (int i = 0; i<n; ++i) {
        auto it = lower_bound(tmp.begin(),tmp.end(),v[i]);

        cout << it-tmp.begin() << ' ';
    }

    return 0;
}
