// https://www.acmicpc.net/problem/2110
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin>>n>>c;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int res = 0;
    int low = 1;
    int high = v.back()-v.front()+1; // [low,high)
    while (low<high) {
        int mid = (low+high)/2;
        int cnt = 1;
        int cur = v.front();
        for (int i = 1; i<n; ++i) {
            if (v[i]-cur>=mid) {
                ++cnt;
                cur=v[i];
            }
        }
        if (cnt>=c) {
            low=mid+1;
            res=mid;
        }
        else {
            high=mid;
        }
    }
    cout << res;

    return 0;
}
