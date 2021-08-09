// https://www.acmicpc.net/problem/1477
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l;
    cin>>n>>m>>l;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    v.push_back(0); // lower_bound
    v.push_back(l); // upper_bound
    n+=2; // n(lower_bound,upper_bound)
    sort(v.begin(),v.end());

    int low = v.front()+1; // 고속도로 양 끝에는 휴게소를 설치 못 함
    int high = v.back(); // [low, high)
    while (low<high) {
        int mid = (low+high)/2;
        if (!mid) {
            break;
        }
        int cnt = 0;
        for (int i = 1; i<n; ++i) {
            cnt+=(v[i]-v[i-1]-1)/mid;
        }
        if (cnt>m) {
            low=mid+1;
        }
        else {
            high=mid;
        }
    }
    cout << low;

    return 0;
}
