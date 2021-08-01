// https://www.acmicpc.net/problem/1463
#include <bits/stdc++.h>

using namespace std;

// 1. DP 테이블
// d[i]: i를 1로 만들기 위해 필요한 연산의 최소 회수
int d[1'000'001]; // 0, 1 ~ 1,000,000

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // 2. 초기치 정의
    // d[0]=0 (not allow)
    //  -> 전역변수에 의해 자동 설정
    // d[1]=0 (연산 불필요)
    d[1]=0;

    for (int i = 2; i<=n; ++i) {
        // 3. 점화식 설계
        // d[i]를 1로 만들기 위한 방법:
        //   1)  3으로 나누기
        //   2)  2로 나누기
        //   3)  1 빼기
        // ex)  1->X(0)
        //      2->2/1 or 1-1(1)
        //      3->3/1(1)
        //      4->4/2 and 2/1 or 1-1(2)
        //      5->5-1 and 4/2 and 2/1 or 1-1(3)
        //      ...
        
        // 1을 뺀다.
        d[i]=d[i-1]+1;
        // 2로 나누어 떨어지면, 2로 나눈다.
        if (!(i%2)) {
            d[i]=min(d[i],d[i/2]+1);
        }
        // 3으로 나누어 떨어지면, 3으로 나눈다.
        if (!(i%3)) {
            d[i]=min(d[i],d[i/3]+1);
        }
    }
    cout << d[n];

    return 0;
}
