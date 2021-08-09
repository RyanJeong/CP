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
    int max_val = 0;
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
        sum+=v[i];
        max_val=max(max_val,v[i]);
    }

    int low = max_val; // 구슬 개수가 4개고, 그룹 수가 4개라면, 
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

    int size = 0;
    sum=0;
    for (int i = 0; i<n; ++i) {
        sum+=v[i];
        if (sum>low) {
            cout << size << ' ';
            size=0;
            sum=v[i];
            --m;
        }
        ++size;
        if (n-i==m) {
            break;
        }
    }
    while (m--) {
        cout << size << ' ';
        size=1;
    }

    return 0;
}
