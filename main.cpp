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
            // 
        }
    }
    cout << res;

    return 0;
}