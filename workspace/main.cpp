// https://www.acmicpc.net/problem/2613
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    int sum = 0;
    int tmp = 0;
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
        sum+=v[i];
        tmp=max(tmp,v[i]);
    }

    int low = tmp; // 구슬 개수가 4개고, 그룹 수가 4개라면, 
                   // 하한은 각 구슬 중 가장 큰 값
    int high = sum+1; // [low,high)
    while (low<high) {
        int mid = (low+high)/2;
        int cnt = 1;
        sum=0;
        for (int i = 0; i<n; ++i) {
            sum+=v[i];
            if (sum>mid) {
                ++cnt;
                sum=v[i];
            }
        }
        if (cnt>m) {
            low=mid+1;
        }
        else {
            high=mid;
        }
    }
    cout << low << '\n';

    int cnt = 1;
    sum=v[0];
    for (int i = 1; i<n; ++i) {
        sum+=v[i];
        if (sum>low) {
            cout << cnt << ' ';
            cnt=1;
            sum=v[i];
        }
        else {
            ++cnt;
        }
    }
    cout << cnt;

    return 0;
}