// https://www.acmicpc.net/problem/11726
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 설정
// d[i]: 2xi 크기의 직사각형을 채우는 방법 수
int d[1'001]; // 0, 1 ~ 1,000

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // 2. 초기치 설정
    // 타일 종류: 1x2, 2x1
    // 2x1: 1 (|)
    // 2x2: 2 (|| or =)
    d[1]=1;
    d[2]=2;
    for (int i = 3; i<=n; ++i) {
        // 3. 점화식 설계
        // 2x3  (d[n-1]) + |
        //      (d[n-2]) + =
        // 2x4: (d[n-1]) + |
        //      (d[n-2]) + =
        d[i]=(d[i-1]+d[i-2])%10'007;
    }
    cout << d[n];

    return 0;
}