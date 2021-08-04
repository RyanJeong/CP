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

        auto low = v.begin();
        auto high = v.end();
        while (low<high) {
            auto mid = low+(high-low)/2;
            if (target<*mid) {
                high=mid;
            }
            else if (*mid<target) {
                low=mid+1;
            }
            else {
                break;
            }
        }
        cout << ((low<high) ? 1 : 0) << '\n';
    }

    return 0;
}
