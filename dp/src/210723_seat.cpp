// https://www.acmicpc.net/problem/2302
// 극장 좌석
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1. 테이블 설정
    // d[i]: 좌석이 i개일 때, 허용되는 좌석 배치 경우의 수
    static int d[41]; // 1-based
    int n, m;
    cin>>n>>m;
    // 2. 초기치 설정
    /*
        i: 1
            {1}
        i: 2
            {1 2}
            {2 1}
        i: 3
            {1 2 3} 
            {2 1 3} => d[2]+{3}
            ------
            {1 3 2} => d[1]+{3 2}
        i: 5
            {1 2 3 4}
            {2 1 3 4}
            {1 3 2 4} => d[3]+{4}
            ---------
            {1 2 4 3}
            {2 1 4 3} => d[2]+{4 3}
        => fibonacci
    */
    d[0]=1; // input: 3 3 1 2 3 -> must be 1
    d[1]=1;
    d[2]=2;
    // 3. 점화식 설계
    // fibonacci
    for (int i = 3; i<=n; ++i) {
        d[i]=d[i-1]+d[i-2];
    }
    int res = 1;
    int prev = 1;
    for (int i = 1; i<=m; ++i) {
        int cur;
        cin>>cur;
        res*=d[cur-prev];
        //[)
        prev=cur+1;
    }
    //[)
    res*=d[n+1-prev];
    cout << res;

    return 0;
}