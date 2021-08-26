// https://www.acmicpc.net/problem/5058
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
        vector<pair<int, int>> v;
        for (int i = 1; i<=n; ++i) {
            int a, b;
            cin>>a>>b;
            v.push_back({a,-b});
        }
        sort(v.begin(),v.end());

        vector<int> lis;
        for (int i = 0; i<n; ++i) {
            int& e = v[i].second;
            if (lis.empty() || e>=lis.back()) {
                lis.push_back(e);
            }
            else {
                *upper_bound(lis.begin(),lis.end(),e)=e;
            }
        }
        cout << lis.size() << '\n';
    }

    return 0;
}
