# Recursion
* 추천 문제
    * [[BOJ] 곱셈](https://www.acmicpc.net/problem/1629) [(소스코드)](./src/mul.cpp)
    * [[BOJ] 하노이 탑 이동 순서](https://www.acmicpc.net/problem/11729) [(소스코드)](./src/hanoi.cpp)
    * [[BOJ] Z](https://www.acmicpc.net/problem/1074) [(소스코드)](./src/z.cpp)

## 재귀 (Recursion)
* 자신을 정의할 때 자기 자신을 재참조하는 방법
* 수학적 귀납법에서 사용되는 논리 전개 방식이 재귀 함수 구현에 그대로 적용됨
    * [유한 귀납법](https://namu.wiki/w/%EC%88%98%ED%95%99%EC%A0%81%20%EA%B7%80%EB%82%A9%EB%B2%95#s-1.1)
    > 도미노를 통해 귀납적인 논리 전개 방식을 설명하면:<br>
      1. 첫 번째에 세워져 있는 도미노가 쓰러지는지 확인한다 (기저 조건).<br>
      2. 무작위로 고른 <i>n</i> 번째에 세워져 있는 도미노가 쓰러질 때, 항상 <i>n+1</i> 번째에 세워져 있는 도미노도 쓰러지는지 확인한다 (귀납 조건). <br>
      위 두 가지 조건을 만족하면 전체 도미노가 쓰러지게 된다고 확신할 수 있다. 
```c++
unsigned int factorial(unsigned int n)
{
    if (n<=1) {

        return 1;
    }
    else {

        return n*factorial(n-1);
    }
}
```
* `factorial(n)`은 <i>n</i> × (<i>n</i>-1) × ⋯ × 1을 계산한다. 
1. `factorial(1)`은 1을 반환한다. (기저 조건이자 재귀의 수렴 조건)
2. `factorial(n)`은 `n*factorial(n-1)`을 반환하고, `factorial(n+1)`은 `(n+1)*factorial(n)`을 반환한다. 
    1. `factorial(n)` = <i>n</i> × (<i>n</i>-1) × ⋯ × 1
    2. 양 변에 (<i>n</i>+1)을 곱하면, `(n+1)*factorial(n)` = (<i>n</i>+1) × <i>n</i> × (<i>n</i>-1) × ⋯ × 1
    3. `factorial(n+1)`<br>
    = `(n+1)*factorial(n)`<br>
    = (<i>n</i>+1) × <i>n</i> × (<i>n</i>-1) × ⋯ × 1



## [TCO(Tail Call Optimization)](https://stackoverflow.com/q/310974/783743)
> In computer science, a tail call is a subroutine call <b>performed as the final action of a procedure</b>. If a tail call might lead to the same subroutine being called again later in the call chain, the subroutine is said to be tail-recursive, which is a special case of recursion. Tail recursion (or tail-end recursion) is particularly useful, and often easy to handle in implementations.

* 재귀 호출은 구현상 간결하다는 이점이 있지만, 재귀가 깊어짐에 따라 스택 영역 메모리를 사용하게 됨
    * 재귀 함수가 호출될 때마다 새로운 스택 프레임을 만들어 사용
    ```c++
    // normal recursion:

        factorial(10);
        ...

    unsigned int factorial(unsigned int n)
    {
        if (n<=1) {

            return 1;
        }
        else {

            return n*factorial(n-1);
        }
    }
    ```
    * Stack frame of the function when argument is 4:<br>
    `factorial(4):(4*factorial(3))`<br>
    `factorial(4):(4*factorial(3))`→`factorial(3):(3*factorial(2))`<br>
    `factorial(4):(4*factorial(3))`→`factorial(3):(3*factorial(2))`→`factorial(2):(2*factorial(1))`<br>
    `factorial(4):(4*factorial(3))`→`factorial(3):(3*factorial(2))`→`factorial(2):(2*factorial(1))`→`factorial(1):(1)`<br>
    `factorial(4):(4*factorial(3))`→`factorial(3):(3*factorial(2))`→`factorial(2):(2*1)`<br>
    `factorial(4):(4*factorial(3))`→`factorial(3):(3*2*1)`<br>
    `factorial(4):(4*3*2*1)`<br>

* 꼬리 재귀를 사용하면 스택 영역 메모리를 일정 크기만 사용하게 됨
    * 꼬리 재귀는 처음 함수가 호출될 때 생성된 스택 프레임을 종료될 때까지 사용
    ```c++
    // tail recursion

        factorial(10);
        ...

    unsigned int factorial(unsigned int n)
    {
        return fact(n,1);
    }
    
    unsigned int fact(unsigned int n, unsigned int result)
    {
        if (n<=1) {

            return result;
        }
        else {

            return fact(n-1,n*result);
        }
    }
    ```
    * Stack frame of the function when argument is 4:<br>
    * Stack frame of the function when argument is 4:<br>
    `factorial(4, 1):(factorial(3, 4))`<br>
    `factorial(3, 4):(factorial(2,12))`<br>
    `factorial(2,12):(factorial(1,24))`<br>
    `factorial(1,24):(24)`<br>

    * `fact` 함수는 컴파일러에 의해 아래와 같이 최적화
    ```c++
    // goto
    unsigned int fact(unsigned int n, unsigned int result)
    {
    BEGINNING:
        if (n<=1) {
            
            return result;
        }
        else {
            result*=n;
            --n;
            goto BEGINNING;
        }
    }
    ```
    ```c++
    // while
    unsigned int fact(unsigned int n, unsigned int result)
    {
        while (n) {
            result*=n;
            --n;
        }

        return result;
    }
    ```

### 연습문제
* [[BOJ] EKO](https://www.acmicpc.net/problem/2805) [(소스코드)](./src/eko.cpp) - 꼬리재귀 형태로 함수 작성 
###### Memory: 5,928 KB, Time: 248 ms
```c++
// https://www.acmicpc.net/problem/2805
#include <bits/stdc++.h>

using namespace std;

void rec(int, int, int); // low, high, target

vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    v=vector<int>(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    rec(0,v.back(),m);

    return 0;
}

void rec(int low, int high, int target)
{
    if (low>high) {
        cout << high;

        return;
    }
    int mid = (low+high)/2;
    long long total = 0;
    for (int t : v) {
        if (t>mid) {
            total+=t-mid;
        }
    }
    if (total==target) {
        cout << mid;

        return;
    }
    else if (total>target) {
        rec(mid+1,high,target);
    }
    else {
        rec(0,mid-1,target);
    }
}
```

---
|[이전 - BFS & DFS](/bfs_dfs/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Dynamic Programming](/dp/)|
|-|-|-|