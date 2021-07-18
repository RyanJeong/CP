// https://www.acmicpc.net/problem/19566
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    //     i j
    // 1 3 2 2 
    // 1 <= i <= j <= n
    // a[i]+...+a[j]/(j-i+1) = k
    // -> s[j]-s[i-1]/(j-i+1) = k
    // -> s[j]-s[i-1] = k(j-i+1)
    // -> s[j]-kj = s[i-1]-k(i-1)
    

    // case 1. n = 1, k = 1, a[1] = 1
    // [1, 1]
    // s[1]-s[0]/(1-0+1) = 1
    // s[1]-s[0] = 1(1-0+1)
    // s[1]-1 = s[0]-0 = 0

    // case 2. n = 4, k = 2, a[1] = 2, a[2] = 1, a[3] = 2, a[4] = 3
    // s[1] = 0, s[1] = -1, s[2] = -1, s[3] = 0
    // s[1] = -1, s[2] = -1, s[3] = 0
    // s[j] 
    static long long sum[200'001];
    int n, k;
    cin>>n>>k;
    set<long long> s;
    for (int i = 1; i<=n; ++i) {
        long long a;
        cin>>a;
        sum[i]=a+sum[i-1]-k;
        s.insert(sum[i]);
    }
    cout << s.size();

    return 0;
}