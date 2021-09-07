#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
        v[i]+=v[i-1];
    }
    
    int m;
    cin>>m;
    while (m--) {
        int i, j;
        cin>>i>>j;
        cout << v[j]-v[i-1] << '\n';
    }

    return 0;
}