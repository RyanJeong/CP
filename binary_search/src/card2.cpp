// https://www.acmicpc.net/problem/10816
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
        int t;
        cin>>t;

        cout << upper_bound(v.begin(),v.end(),t)-lower_bound(v.begin(),v.end(),t) << ' ';
    }    

    return 0;
}