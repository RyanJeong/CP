// https://www.acmicpc.net/problem/1015
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v.begin(),v.end());

    /*
        {2,0}    {1,2}
        {3,1} -> {2,0} 
        {1,2}    {3,1}
    */
    vector<int> res(n);
    for (int i = 0; i<n; ++i) {
        res[v[i].second]=i;
    }
    for (auto i : res) {
        cout << i << ' ';
    }

    return 0;
}
