// https://www.acmicpc.net/problem/2532
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
/* ex. 

    5
    1 0 10
    2 0 5
    3 3 10
    4 3 4
    5 2 5

    1>2>5>4 => 4
*/

    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for (int i = 1; i<=n; ++i) {
        int a, r, l;
        cin>>a>>r>>l;
        v.push_back({r,-l});
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    n=v.size();

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
    cout << lis.size();

    return 0;
}