// http://icpc.me/11652
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long max_num = -(1ll<<62)-1; // -2^62 <= ... 
    int cnt = 1;
    int max_cnt = 0;
    int n;
    cin>>n;
    long long arr[100'002]; // 0, 1 ~ 100,000, OOB
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }
    arr[n]=(1ll<<62)+1;

    sort(arr,arr+n);
    for (int i = 1; i<=n; ++i) {
        if (arr[i-1]!=arr[i]) {
            if (cnt>max_cnt) {
                max_cnt=cnt;
                max_num=arr[i-1];
            }
            cnt = 1;
        } 
        else {
            ++cnt;
        }
    }
    cout << max_num;

    return 0;
}