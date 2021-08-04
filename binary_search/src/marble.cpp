// https://www.acmicpc.net/problem/2792
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int> v(m);
    for (int i = 0; i<m; ++i) {
        cin>>v[i];
    } 
    sort(v.begin(),v.end());

    int res = v.back();
    int low = 1;
    int high = v.back()+1; // [low, high)
    while (low<high) {
        int mid = (high+low)/2;
        int cnt = 0;
        for (int j : v) {
            cnt+=j/mid;
            if (j%mid) {
                ++cnt;
            }
        }
        if (cnt<=n) {
            high=mid; // cnt ∝ mid
            res=min(res,mid);
        }
        else {
            low=mid+1;
        }
    }
    cout << res;

    return 0;
}
