# DP
* 추천 문제
    * [[BOJ] Jump The Board!](https://www.acmicpc.net/problem/1890) [(소스코드)](./src/jump.cpp)
        * 초기에 백트래킹을 사용해 접근했으나, [TLE](./src/jump_tle.cpp)가 발생
        * 이처럼 탐색 경우의 수가 방대할 경우, DP를 사용해 해결해야 함
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

## 누적합(Prefix Sum)
* 추천 문제
    * [[BOJ] 두 배열의 합](https://www.acmicpc.net/problem/2143) [(소스코드)](./src/prefix_sum_matrix.cpp) - 부분합을 구한 뒤에 `lower_bound()`, `upper_boud()`를 이용해 조건을 만족하는 경우를 찾는 문제
    * [[BOJ] 색종이 - 3](https://www.acmicpc.net/problem/2571) [(소스코드)](./src/prefix_sum_colored_paper.cpp) - 2차원 배열에서의 구간 합을 계산한 뒤에, 조건을 만족하는 경우만 판별
    * [[BOJ] 수열의 구간 평균](https://www.acmicpc.net/problem/19566) [(소스코드)](./src/prefix_sum_seq_avg.cpp)

### 정의
* 배열 안 요소의 값이 변하지 않는다면, 임의의 연속된 구간 내 요소들의 합을 기록해 필요할 때 이를 활용하는 기법
* 크기가 <i>n</i>인 1차원 배열에서의 누적합 <i>s<sub>i</sub></i> :

    ![prefix_sum](./img/prefix_sum_1.png)

* 크기가 <i>n</i>인 1차원 배열에서의 임의의 연속된 구간 내 요소들의 합:

    ![prefix_sum](./img/prefix_sum_2.png)

* 크기가 <i>n</i>×<i>m</i>인 2차원 배열에서의 누적합 <i>s<sub>i,j</sub></i> :

    ![prefix_sum](./img/prefix_sum_3.png)

* 크기가 <i>n</i>×<i>m</i>인 2차원 배열에서의 임의의 연속된 구간 내 요소들의 합:

    ![prefix_sum](./img/prefix_sum_4.png)

### 연습문제
* [[BOJ] 구간 합 구하기 4](https://www.acmicpc.net/problem/11659) [(소스코드)](./src/prefix_sum_1d.cpp) - 1차원 배열에서의 구간 합
###### Memory: 2,800 KB, Time: 40 ms
```c++
// https://www.acmicpc.net/problem/11659
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int s[100'001]; // s[i] = s[i-1] + a[i]
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        int a;
        cin>>a;
        s[i]=s[i-1]+a;
    }
    while (m--) {
        int i, j;
        cin>>i>>j;
        cout << s[j]-s[i-1] << '\n';
    }

    return 0;
}
```

* [[BOJ] 구간 합 구하기 5](https://www.acmicpc.net/problem/11660) [(소스코드)](./src/prefix_sum_2d.cpp) - 2차원 배열에서의 구간 합
###### Memory: 6,124 KB, Time: 124 ms
```c++
// https://www.acmicpc.net/problem/11660
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int s[1025][1025]; // s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1]
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            int a;
            cin>>a;
            s[i][j]=a+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        cout << s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1] << '\n';
    }

    return 0;
}
```

## 최장 증가 부분수열(Longest Increasing Subsequence, LIS)
* 추천 문제
    * [[BOJ] 가장 큰 증가 부분 수열](https://www.acmicpc.net/problem/11055) [(소스코드)](./src/lis_app1.cpp) - LIS 응용, 조건을 만족하는 값들을 누적하는 문제
    * [[BOJ] 전깃줄](https://www.acmicpc.net/problem/2565) [(소스코드)](./src/wire1.cpp) - <b>O(<i>n</i><sup>2</sup>)</b>로 해결할 수 있는 문제
    * [[BOJ] 반도체 설계](https://www.acmicpc.net/problem/2352) [(소스코드)](./src/semiconductor.cpp) - 이분탐색을 이용해 시간복잡도를 <b>O(<i>n</i> log <i>n</i>)</b>로 낮추어 해결해야 하는 문제 1
    * [[BOJ] 주식](https://www.acmicpc.net/problem/12014) [(소스코드)](./src/stock.cpp) - 이분탐색을 이용해 시간복잡도를 <b>O(<i>n</i> log <i>n</i>)</b>로 낮추어 해결해야 하는 문제 2
    * [[BOJ] 전깃줄 - 2](https://www.acmicpc.net/problem/2568) [(소스코드)](./src/wire2.cpp) - 이분탐색과 부분 수열을 출력해야 하는 문제
    * [[BOJ] 이상한 전깃줄](https://www.acmicpc.net/problem/16474) [(소스코드)](./src/weird_wire.cpp) - 이분탐색과 부분 수열을 출력해야 하는 문제

### 정의
* 임의의 수열이 주어졌을 때, 수열의 요소 값이 오름차순으로 등장하는 가장 긴 구간을 의미
* 구간 내 모든 요소들이 오름차순 상태가 아닐 수 있음
    * 수열 <i>a</i> = {3,1,4,2,6,8,5}가 주여졌을 때, LIS는 {1,2,6,8}

* 임의의 수열 내 LIS가 두 개 이상 존재할 수 있음
    * 수열 <i>a</i> = {3,5,7,9,2,1,4,8}가 주어졌을 때, LIS는 {3,5,7,9}, {3,5,7,8}

* 크기가 <i>n</i>인 수열 <i>a</i>에서의 LIS <i>l<sub>i</sub></i> :

    ![LIS](./img/lis.png)

### 연습문제
* [[BOJ] 가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053) [(소스코드)](./src/lis_1.cpp) - <b>O(<i>n</i><sup>2</sup>)</b>
###### Memory: 2,028 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/11053
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[1'001];
    static int lis[1'001];
    int n;
    cin>>n;
    for (int i = 1; i<=n; ++i) {
        cin>>arr[i];
    }

    // O(n^2)
    int res = 1;
    lis[1]=1;
    for (int i = 2; i<=n; ++i) {
        for (int j = 1; j<i; ++j) {
            if (arr[i]>arr[j]) {
                lis[i]=max(lis[i],lis[j]+1);
            }
            else {
                lis[i]=max(lis[i],1);
            }
        }
        res=max(res,lis[i]);
    }
    cout << res;

    return 0;
}
```

* [[BOJ] 가장 긴 바이토닉 부분 수열](https://www.acmicpc.net/problem/11054) [(소스코드)](./src/bitonic.cpp) - 가장 긴 증가하는 부분 수열 + 가장 긴 감소하는 부분 수열
###### Memory: 2,028 KB, Time: 0 ms
```c++
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
```

* [[BOJ] 가장 긴 증가하는 부분 수열 2](https://www.acmicpc.net/problem/12015) [(소스코드)](./src/lis_2.cpp) - 이분탐색을 사용하면 시간복잡도를 <b>O(<i>n</i> log <i>n</i>)</b>으로 줄일 수 있음 
    * 전략:
    1. 수열의 첫 요소를 `vector`에 넣는다.
    2. 다음 요소와 `vector`의 끝 요소(`back()`)를 비교해 다음 요소가 더 크다면 `vector`에 삽입(`push_back()`)하고, 그렇지 않다면 `lower_bound()` 함수를 통해 해당 요소가 삽입될 위치를 찾는다.
    * 예를 들어, 수열 <i>a</i> = {10,20,10,30,20,50}가 주어진다면, `vector`의 값은 아래와 같이 채워지게 됨:
    ```text
    a[1] = 10, vector = {10}
    a[2] = 20, vector = {10,20}
    a[3] = 10, vector = {10,20}
               index 0 위치에 a[3] 삽입
    a[4] = 30, vector = {10,20,30}
    a[5] = 20, vector = {10,20,30}
               index 1 위치에 a[5] 삽입
    a[6] = 50, vector = {10,20,30,50}
    ```
    * 수열 <i>a<sub>t</sub></i> = {3,4,5,1,2}가 주어졌을 때, <b>`vector`에 저장된 요소들은 수열 <i>a<sub>t</sub></i>의 부분수열이 아닐 수 있음</b>
    ```text
    vector = {2,4,5}
    ```
    * <b>`vector`의 의미는 길이가 <i>i</i>인 증가 부분수열 중에서 마지막 요소의 값이 가장 작은 값임을 의미</b>
    * 수열의 다음 요소 중에서 증가 부분수열이 발견될 수 있기 때문에, 모든 경우를 처리하기 위한 정보를 기록
    * <b>즉, {3,4,5}가 수열 <i>a<sub>t</sub></i>에서의 가장 긴 증가하는 부분 수열이지만, 혹시 모를 뒤따르는 증가 부분수열을 처리하기 위해 `vector`의 1 번째 요소를 `3`에서 `2`로 바꾸어놓은 것</b>
    * 수열 <i>a<sub>s</sub></i> = {1,2,5,6,3}이 주어졌을 때, 4 번째 요소(`6`)까지 탐색을 마쳤을 경우 해당 수열에서의 증가 부분수열 후보는 {1,2}, {5,6}
    * 만약, {5,6}에 대한 정보를 `vector`에 기록해 두었다면, 5 번째 요소(`3`)를 처리할 수 없음
    * <b>`vector`에 {5,6}이 아닌 길이가 <i>i</i>인 증가부분 수열 중 마지막 원소의 값이 가장 작은 값인 {1,2}로 기록해 놓는다면, 5 번째 요소 `3`을 올바르게 처리할 수 있음</b>
###### Memory: 12,200 KB, Time: 164 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }

    vector<int> lis;
    lis.push_back(v[1]);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
        }
    }
    cout << lis.size();

    return 0;
}
```

* [[BOJ] 가장 긴 증가하는 부분 수열 4](https://www.acmicpc.net/problem/14002) [(소스코드)](./src/lis_4.cpp) - 가장 긴 증가하는 부분 수열의 크기와 실제 부분수열을 출력하는 문제
    * 전략:
    1. <i>LIS</i>를 계산하면서 각 요소의 길이를 따로 기록
    2. 마지막 요소에서부터 첫 번째 요소까지 순회하면서 부분수열의 크기와 일치하는 요소를 `stack`에 넣고, 다음에는 부분수열의 크기보다 1 작은 요소를 `stack`에 넣고, ..., 길이가 1인 요소를 `stack`에 삽입
    ```text
    a = {2 3 1 4}
    subsequence: {2 3 4}, size: 3

    idx   1 2 3 4 
    a[i]  2 3 1 4 
    len   1 2 1 3 

    stack 4 3 2 <- top()
    ```
    ```text
    a = {10 3 7 4 1 8}
    subsequence: {3 4 8} or {3 7 8}, size: 3

    idx    1 2 3 4 5 6
    a[i]  10 3 7 4 1 8
    len    1 1 2 2 1 3

    stack 8 4 3 <- top()
    ```
    3. `stack`에 삽입된 값들을 출력하면 역순으로 입력된 부분 수열이 올바르게 출력됨

###### Memory: 2,156 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/14002
// v, len은 1-based, lis는 0-based임
// lis는 실제 요소의 개수가 가장 긴 증가하는 부분 수열의 크기이므로, 0-based를 사용해야 함
// cur-lis.size()+1을 해준 이유는, lis가 0-based이기 때문
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }

    vector<int> lis; // 0-based
    lis.push_back(v[1]); 
    vector<int> len(1);  // 1-based
    len.push_back(1);
    for (int i = 2; i<=n; ++i) {
        if (v[i]>lis.back()) {
            lis.push_back(v[i]);
            len.push_back(lis.size());
        }
        else {
            auto cur = lower_bound(lis.begin(),lis.end(),v[i]);
            lis[cur-lis.begin()]=v[i];
            len.push_back(cur-lis.begin()+1); // 0-based
        }
    }
    int target = lis.size();
    cout << target << '\n';
    stack<int> s;
    for (int i = n; i>0; --i) {
        if (len[i]==target) {
            s.push(v[i]);
            --target;
        }
    }
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }

    return 0;
}
```

* [[WIP][BOJ] 가장 긴 증가하는 부분 수열 6](https://www.acmicpc.net/problem/17411) [(소스코드)](./src/lis_6.cpp) - 가장 긴 증가하는 부분 수열의 크기와 부분 수열의 개수를 출력하는 문제
###### Memory:  KB, Time:  ms
```c++
// WIP
```


## 최장 공통 부분수열(Longest Common Subsequencd, LCS)
* 추천 문제
    * [[Codeforces] B. Catching Cheaters](https://codeforces.com/contest/1446/problem/B) [(소스코드)](./src/cheater.cpp) - LCS를 이용한 기본 문제
    * [[BOJ] LCS 4](https://www.acmicpc.net/problem/13711) [(소스코드)](./src/lcs4.cpp) - LIS와 LCS를 조합한 문제

### 정의
* 임의의 두 수열이 주어졌을 때, 어떠한 부분수열이 두 수열의 부분수열이라면 해당 부분수열을 두 수열의 공통 부분수열이라고 함
* 공통 부분수열 중 길이가 가장 긴 것을 두 수열의 최장 공통 부분수열이라고 함
    * 두 수열 <i>a</i> = {4,2,<b>10</b>,<b>3</b>,1,<b>7</b>,6,<b>8</b>,<b>5</b>,<b>9</b>}, <i>b</i> = {1,4,<b>10</b>,<b>3</b>,2,<b>7</b>,6,<b>8</b>,<b>5</b>,<b>9</b>}가 주어졌을 때, 두 수열의 최장 공통 부분수열 <i>c</i> = {10,3,7,8,5,9}
* LIS처럼 두 수열의 LCS는 두 개 이상 존재할 수 있음

* 크기가 <i>n</i>인 두 수열 <i>a</i>, <i>b</i>에서의 LCS <i>c<sub>i,j</sub></i> :

    ![LIS](./img/lcs.png)

    ![LIS](./img/lcs_exam.png)

### 연습문제
* [[BOJ] LCS](https://www.acmicpc.net/problem/9251) [(소스코드)](./src/lcs.cpp)
###### Memory: 5,940 KB, Time: 4 ms
```c++
// https://www.acmicpc.net/problem/9251
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin>>a>>b;
    int a_len = a.size();
    int b_len = b.size();
    a.insert(a.begin(), '\0'); // 1-based
    b.insert(b.begin(), '\0'); // 1-based

    static int c[1001][1001]; // init. all to zero
    for (int i = 1; i<=a_len; ++i) {
        for (int j = 1; j<=b_len; ++j) {
            if (a[i]==b[j]) {
                c[i][j]=c[i-1][j-1]+1;
            }
            else {
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    cout << c[a_len][b_len];

    return 0;
}

```

* [[BOJ] LCS 2](https://www.acmicpc.net/problem/9252) [(소스코드)](./src/lcs_2.cpp) - LCS를 구한 방법의 반대로 역추적
    1. `a[i]==b[j]`: `i-1, j-1`로 이동
    2. `a[i]!=b[j]`: `c[i][j-1]`와 `c[i-1][j]` 두 값을 비교해 더 큰 방향으로 이동
###### Memory:  KB, Time:  ms
```c++
// https://www.acmicpc.net/problem/9252
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin>>a>>b;
    int a_len = a.size();
    int b_len = b.size();
    a.insert(a.begin(), '\0'); // 1-based
    b.insert(b.begin(), '\0'); // 1-based

    static int c[1001][1001]; // init. all to zero
    for (int i = 1; i<=a_len; ++i) {
        for (int j = 1; j<=b_len; ++j) {
            if (a[i]==b[j]) {
                c[i][j]=c[i-1][j-1]+1;
            }
            else {
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    cout << c[a_len][b_len] << '\n';

    // get lcs
    stack<char> s;
    int a_idx = a_len;
    int b_idx = b_len;
    while (c[a_idx][b_idx]) {
        if (a[a_idx]==b[b_idx]) {
            s.push(a[a_idx]);
            --a_idx;
            --b_idx;
        }
        else {
            if (c[a_idx][b_idx-1]>c[a_idx-1][b_idx]) {
                --b_idx;
            }
            else {
                --a_idx;
            }
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
```

* [[BOJ] LCS 3](https://www.acmicpc.net/problem/1958) [(소스코드)](./src/lcs_3.cpp) - 두 문자열이 아닌 세 문자열에서의 LCS 계산 문제
    * 두 문자열의 LCS를 구한 결과와 나머지 문자열 사이의 LCS를 구하는 방법을 시도했다가 실패했으며, 반례는 아래와 같음:
    ```text
    A: dababcf
    B: ababdef
    C: df

    LCS(A,B)       : ababf
    LCS(LCS(A,B),C): f
    LCS(A,B,C)     : df
    ```
    * 따라서 세 문자열을 동시에 LCS 계산하는 데 사용해야 함
###### Memory: 6,048 KB, Time: 4 ms
```c++
// https://www.acmicpc.net/problem/1958
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y, z;
    cin>>x>>y>>z;
    int x_len = x.size();
    int y_len = y.size();
    int z_len = z.size();
    x.insert(x.begin(), '\0'); // 1-based
    y.insert(y.begin(), '\0'); // 1-based
    z.insert(z.begin(), '\0'); // 1-based
    static int c[101][101][101]; // init. all to zero
    for (int i = 1; i<=x_len; ++i) {
        for (int j = 1; j<=y_len; ++j) {
            for (int k = 1; k<=z_len; ++k) {
                if (x[i]==y[j] && y[j]==z[k]) {
                    c[i][j][k]=c[i-1][j-1][k-1]+1;
                }
                else {
                    c[i][j][k]=max({c[i-1][j][k],c[i][j-1][k],c[i][j][k-1]});
                }
            }
        }
    }
    cout << c[x_len][y_len][z_len];

    return 0;
}
```

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
|[이전 - Recursion](/recursion/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Greedy](/greedy/)|
|-|-|-|