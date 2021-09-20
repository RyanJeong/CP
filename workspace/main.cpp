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
    long long cluster;
    cin>>cluster;

    long long cnt = 0;
    for (int i = 0; i<n; ++i) {
        cnt+=v[i]/cluster;
        if (v[i]%cluster) {
            ++cnt;
        }
    }
    cout << cluster*cnt;

    return 0;
}