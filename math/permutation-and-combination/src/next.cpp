// https://www.acmicpc.net/problem/10972
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

    if (next_permutation(v.begin(),v.end())) {
        for (auto i : v) {
            cout << i << ' ';
        }
    }
    else {
        cout << -1;
    }

    return 0;
}
