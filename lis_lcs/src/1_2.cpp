// https://www.acmicpc.net/problem/12852
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 설계
// d[i]: i를 1로 만들기 위해 필요한 연산의 최소 회수
int d[1'000'001]; // 0, 1 ~ 1,000,000
// p[i]: i를 1로 만들기 위해 거치는 경로
int p[1'000'001]; // path

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    // 2. 초기치 정의
    // d[0]=0 (not allow)
    // p[0]=0 (not allow)
    //  -> 전역변수에 의해 자동 설정
    // d[1]=0 (연산 불필요)
    // p[1]=0 (i의 값이 1이므로, 경로가 없음)
    d[1]=0;
    p[1]=0;
    for (int i = 2; i <= n; ++i) {
        // 3. 점화식 설계
        // d[i]를 1로 만들기 위한 방법:
        //   1)  3으로 나누기
        //   2)  2로 나누기
        //   3)  1 빼기

        // 1을 뺀다.
        d[i]=d[i-1]+1;
        p[i]=i-1;
        // 2로 나누어 떨어지면, 2로 나눈다.
        if (!(i%2)) {
            // 최소 연산일 경우, d와 p 갱신
            if (d[i]>d[i/2]+1) {
                d[i]=d[i/2]+1;
                p[i]=i/2;
            }
        }
        // 3으로 나누어 떨어지면, 3으로 나눈다.
        if (!(i%3)) {
            // 최소 연산일 경우, d와 p 갱신
            if (d[i]>d[i/3]+1) {
                d[i]=d[i/3]+1;
                p[i]=i/3;
            }
        }
    }
    cout << d[n] << '\n';
    while (n) {
        cout << n << ' ';
        n=p[n];
    }

    return 0;
}
