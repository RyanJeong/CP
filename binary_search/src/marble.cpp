// https://www.acmicpc.net/problem/2792
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 최적화 문제: 보석을 어린이에게 나누어줄 때, 한 어린이가 표현할 수 있는 최소 질투 지수
    // 결정 문제: 보석을 x개씩 나누어줬을 때의 대상 수가 n개 이하인가? (최소)
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
            res=mid;
        }
        else {
            low=mid+1;
        }
    }
    cout << res;

    return 0;
}
