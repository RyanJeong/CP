# DP
* 추천 문제
    * [[BOJ] 행렬 곱셈 순서](https://www.acmicpc.net/problem/11049) [(소스코드)](./src/210709_matrix.cpp)

## 다이나믹 프로그래밍(동적 계획법)
* 주어진 문제를 작은 단위로 나누어 각 단위에서의 결과를 계산하고, 이 계산한 결과를 원래 문제를 해결하는 데 사용
* 작은 단위에서 계산한 결과를 저장해둔 뒤 원래 문제를 해결할 때 재사용
    * 작은 단위에서 계산한 결과를 저장함으로써, 계산 속도를 향상시킬 수 있음
### 전략
1. 본래 문제를 작은 단위로 쪼개어 계산한 결과를 기록할 테이블 설정
    * 해당 테이블에서의 각 요소에 어떤 값을 기록할 것인지 정해야 함
2. 초기치 설정
3. 초기치를 이용한 점화식 설계

### 연습문제
* [[BOJ] 1로 만들기](https://www.acmicpc.net/problem/1463) [(소스코드)](./src/1.cpp)
###### Memory: 5,928 KB, Time: 4 ms
```c++
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
```

* [[BOJ] Adding 1s, 2s, and 3s](https://www.acmicpc.net/problem/9095) [(소스코드)](./src/adding_1_2_3.cpp)
###### Memory: 2,020 KB, Time: 0 ms
```c++
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
```

* [[BOJ] 계단 오르기](https://www.acmicpc.net/problem/2579) [(소스코드)](./src/stair.cpp)
###### Memory: 2,020 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/2579
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 정의
// d[i][j]: i 번째 계단을 밟았으며, 
//          이때 이전에 j 개의 계단을 밟았을 때의 총 점수
int d[302][2]; 
int s[302];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        cin>>s[i];
    }

    if (n==1) {
        cout << s[1];
    } 
    else {
        // 2. 초기치 설정
        // d[1][0]: 이전에 밝은 계단이 없으므로, S[1]
        // d[1][1]: 이전에 밟은 계단이 1개이지만,
        //          i 번째 계단이 시작점이기에 0으로 기록
        // d[2][0]: 이전에 밟은 계단이 없으므로, S[2]
        // d[2][1]: 이전에 밟은 계단이 1개이므로 S[1]+S[2]
        d[1][0]=s[1];
        d[1][1]=0;
        d[2][0]=s[2];
        d[2][1]=s[1]+s[2];
        for (int i = 3; i<=n; ++i) {
            // 3. 점화식 설계
            // 3-1. 이전 계단을 밟지 않을 경우
            // 3-2. 이전 계단을 밟을 경우
            d[i][0]=max(d[i-2][0],d[i-2][1])+s[i];
            d[i][1]=d[i-1][0]+s[i];
        }
        cout << max(d[n][0],d[n][1]);
    }

    return 0;
}
```

* [[BOJ] RGB거리](https://www.acmicpc.net/problem/1149) [(소스코드)](./src/rgb1.cpp)
###### Memory: 2,020 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/1149
#include <bits/stdc++.h>

using namespace std;

// 1. 테이블 정의
// d[i][j]
// i번째 집을 j 색으로 칠할 때의 최소 비용
int d[1'001][3];
int r[1'001], g[1'001], b[1'001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    for (int i = 1; i<=n; ++i) {
        cin>>r[i]>>g[i]>>b[i];
    }
    // 2. 초기치 설정
    d[1][0]=r[1];
    d[1][1]=g[1];
    d[1][2]=b[1];
    for (int i = 2; i<=n; ++i) {
        // 3. 점화식 설계
        d[i][0]=min(d[i-1][1],d[i-1][2])+r[i];
        d[i][1]=min(d[i-1][0],d[i-1][2])+g[i];
        d[i][2]=min(d[i-1][0],d[i-1][1])+b[i];
    }
    cout << min({d[n][0],d[n][1],d[n][2]});

    return 0;
}
```

* [[BOJ] 2×n 타일링](https://www.acmicpc.net/problem/11726) [(소스코드)](./src/2_by_n.cpp)
###### Memory: 2,020 KB, Time: 0 ms
![dp](./img/dp_1.png)
```c++
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
```
* [[BOJ] 1로 만들기 2](https://www.acmicpc.net/problem/12852) [(소스코드)](./src/1_2.cpp)
###### Memory: 9,832 KB, Time: 8 ms
```c++
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

```

## [WIP] 누적합(Prefix Sum)
## [WIP] 최장 증가 부분수열(Longest Increasing Subsequence, LIS)
## [WIP] 최장 공통 부분수열(Longest Common Subsequencd, LCS)
## [WIP] 비트마스크를 이용한 동적 계획법(Bit DP)
* 추천 문제
    * [[BOJ] 행렬 곱셈 순서](https://www.acmicpc.net/problem/11049) [(소스코드)](./src/210709_matrix.cpp)

### [WIP] 부분집합의 합(Sum over Subsets, SOS DP)
* 추천 문제
    * [[BOJ] Binomial](https://www.acmicpc.net/problem/18719) [(소스코드)](./src/sos_dp_binomial.cpp)
    * [[BOJ] KOŠARE](https://www.acmicpc.net/problem/2803) [(소스코드)](./src/sos_dp_toys.cpp)

## [WIP] 냅색(Knapsack)
* 추천 문제
    * [[BOJ] 카우버거 알바생](https://www.acmicpc.net/problem/17208) [(소스코드)](./src/knapsack_cow.cpp)
    * [[BOJ] 행운쿠키 제작소](https://www.acmicpc.net/problem/10982) [(소스코드)](./src/knapsack_cookie.cpp)

### 연습문제
* [[BOJ] 평범한 배낭](https://www.acmicpc.net/problem/12865) [(소스코드)](./src/knapsack.cpp)
###### Memory:  KB, Time:  ms
```c++
```

* [[BOJ] 평범한 배낭2](https://www.acmicpc.net/problem/12920) [(소스코드)](./src/knapsack2.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - Backtracking](/backtracking/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Greedy](/greedy/)|
|-|-|-|