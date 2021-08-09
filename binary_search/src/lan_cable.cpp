// https://www.acmicpc.net/problem/1654
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 최적화 문제: 랜선 n개를 만들 때 각 랜선의 최대 길이
    // 결정 문제: 각 랜선의 길이가 x일 때, 랜선이 n개 이상인가?(최대)
    int k, n;
    cin>>k>>n;
    vector<int> v(k);
    for (int i = 0; i<k; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int res = 0;
    long long low = 1;
    long long high = (long long) v.back()+1; // [low, high)
    while (low<high) {
        long long mid = (low+high)/2;
        int cnt = 0;

        for (int l : v) {
            cnt+=l/mid;
        }
        if (cnt>=n) {
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