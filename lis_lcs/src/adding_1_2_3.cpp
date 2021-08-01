// https://www.acmicpc.net/problem/9095
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 정의
// d[i]: 1, 2, 3을 사용해 표현할 수 있는 총 가지수
// ex. 4
// 1+1+1+1,
// 1+1+2,
// 1+2+1,
// 2+1+1,
// 2+2,
// 1+3, and
// 3+1.
int d[11]; // 0, 1 ~ 10;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    // 2. 초기치 설정
    // d[0]: not allow
    // d[4]: 1+1+1 +1, 2+1 +1, 1+2 +1, 3 +1
    //        -> 3을 1, 2, 3으로 표현할 수 있는 방법, 4
    //       1+1 +2, 2 +2, 
    //        -> 2를 1, 2, 3으로 표현할 수 있는 방법, 2
    //       1 +3, 
    //        -> 1을 1, 2, 3으로 표현할 수 있는 방법, 1
    //        => d[4]=d[3]+d[2]+d[1];
    //        => 초기치 d[3], d[2], d[1]이 필요
    d[1]=1;
    d[2]=2;
    d[3]=4; 
    for (int i = 4; i<11; ++i) {
        d[i]=d[i-1]+d[i-2]+d[i-3];
    }
    while (t--) {
        int n;
        cin>>n;
        cout << d[n] << '\n';
    }

    return 0;
}