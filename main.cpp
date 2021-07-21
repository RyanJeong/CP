// https://www.acmicpc.net/problem/17411
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

    vector<int> lis; // 0-based
    lis.push_back(v[1]); 
    vector<int> len(1);  // 1-based
    len.push_back(1);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
            len.push_back(lis.size());
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
            len.push_back(cur-lis.begin()+1); // 0-based
        }
    }
    cout << lis.size() << ' ';
    const long long mod = 1e9+7;
    for (int i = n; i>0; --i) {
        //dp->len
        //sum?
        //
    }

    return 0;
}