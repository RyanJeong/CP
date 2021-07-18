// https://www.acmicpc.net/problem/19566
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
   
    // a[1], ..., a[i], ..., a[j], ..., a[n]
    // (1<=i<=j<=n)
    // if [i,j]
    // then a[i]+a[i+1]+...+a[j]/(j-i+1) = k
    // = (s[j]-s[i-1])/(j-(i-1)) = k
    // = s[j]-s[i-1] = k(j-(i-1))
    // = s[j]-k*j = s[i-1]-k(i-1)
    // => 누적합의 크기가 같은 요소의 개수가 얼마인가?

    // 0 1 2 3 (index)
    // 1 3 2 2 
    // 1. 각 요소에서 k를 뺀 뒤, 요소를 더했을 때 0이 되는 구간의 개수를 구한다. - (1)
    // -1 1 0 0 -> O(n^2)
    // 2. (1)의 누적합을 구해 누적합이 같은 요소들의 쌍을 구하면, 시간복잡도를 O(nlogn)으로 줄일 수 있다.
    // -1 1 0 0
    // -> -1 0 0 0

    //  0  1  2  3  4  5  6  7  8  9 (index)
    //  2  4  3  1  5  3  2  4  1  3
    // ->
    // -1  1  0 -2  2  0 -1  1 -2  0 (각 요소에 k를 뺀 결과) - (1)
    // -1  0  0 -2  0  0 -1  0 -2 -2 (각 요소에 k를 뺀 결과의 누적합) - (2)

    // 1. index가 0, 6일 때
    // s[j]-k*j = s[i-1]-k(i-1)식에 인덱스를 넣어 보면, 
    // (1)에서 (0,6] 범위에 있는 요소들의 합이 0이 됨을 알 수 있다.
    // 즉, (2)에서 같은 값을 갖는 요소의 쌍 개수가 (1)에서의 구간합이 0이 되는 구간의 수가 된다.
    // (만약 (2)에서의 i번째, j번째 요소의 값이 같다면, 이는 (i,j]의 합이 0이라는 뜻)
    // 2. index가 1일 때
    // (1)  결과에서 [0,1] 범위에 있는 요소들을 더하면 0이 됨을 알 수 있다.
    // 즉, (2)에서 0의 개수가 (1)에서의 구간합이 0이 되는 경우가 된다.
    
    static long long s[200'001];
    int n, k;
    cin>>n>>k;
    long long res = 0;
    map<long long, int> m;
    for (int i = 1; i<=n; ++i) {
        long long a;
        cin>>a;
        s[i]=a+s[i-1]-k;
        if (s[i]==0) {
            ++res;
        }
        if (m.find(s[i])==m.end()) {
            m[s[i]]=1;
        }
        else {
            ++m[s[i]];
        }
    }
    for (auto it = m.begin(); it!=m.end(); ++it) {
        long long tmp = it->second;
        res+=tmp*(tmp-1)/2;
    }
    cout << res;

    return 0;
}
