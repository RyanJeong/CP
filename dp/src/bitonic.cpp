// https://www.acmicpc.net/problem/11054
// {1 5 2 1 4 3 4 5 2 1}
// {1  2      3 4 5}     -> +5(LIS)
//               {5 2 1} -> +3(LDS)
//               {5}     -> -1(DUP)
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[1'001];
    static int lis[1'001];
    static int lds[1'001];
    int n;
    cin>>n;
    lis[1]=1;
    for (int i = 1; i<=n; ++i) {
        cin>>arr[i];
        for (int j = 1; j<i; ++j) {
            if (arr[i]>arr[j]) {
                lis[i]=max(lis[i],lis[j]+1);
            }
            else {
                lis[i]=max(lis[i],1);
            }
        }
    }

    lds[n]=1;
    for (int i = n-1; i>0; --i) {
        for (int j = n; j>i; --j) {
            if (arr[i]>arr[j]) {
                lds[i]=max(lds[i],lds[j]+1);
            }
            else {
                lds[i]=max(lds[i],1);
            }
        }
    }
    int res = 1;
    for (int i = 1; i<=n; ++i) {
        res=max(res,lis[i]+lds[i]);
    }
    cout << res-1;

    return 0;
}
