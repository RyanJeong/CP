// https://www.acmicpc.net/problem/1920
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
    sort(v.begin(),v.end());

    int m;
    cin>>m;
    while (m--) {
        int target;
        cin>>target;

        cout << binary_search(v.begin(),v.end(),target) << '\n';
    }

    return 0;
}