// https://www.acmicpc.net/problem/12014
// 이분 탐색을 이용해 LIS 시간복잡도를 O(n log n)으로 낮추어 해결
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--) {
        static int idx = 1;
        int n, k;
        cin>>n>>k;
        vector<int> v(n+1); // 1-based
        for (int i = 1; i<=n; ++i) {
            cin>>v[i];
        }

        vector<int> lis;
        lis.push_back(v[1]);
        for (int i = 2; i<=n; ++i) {
            if (v[i]>lis.back()) {
                lis.push_back(v[i]);
            }
            else {
                auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
                lis[cur-lis.begin()]=v[i];
            }
        }
        cout << "Case #" << idx++ << '\n';
        cout << ((k>lis.size()) ? 0 : 1) << '\n';
    }

    return 0;
}