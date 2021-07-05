# Recursion
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
* 꼬리 재귀를 사용하면 스택 영역 메모리를 

### 연습문제
* [[BOJ] 로마 숫자 만들기](https://www.acmicpc.net/problem/16922) - `stack`을 이용한 DFS
    * <b>시간 초과</b>
###### TLE(Time Limit Exceeded)
```c++
// https://www.acmicpc.net/problem/16922
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int add[] = {1,5,10,50};
    static bool is_used[50*20+1];
    int count = 0;
    int n;
    cin>>n;

    stack<pair<int, int>> s; // step, num
    s.push({0,0});
    while(!s.empty()) {
        auto cur = s.top();
        s.pop();

        for (int d = 0; d<4; ++d) {
            int step = cur.first+1;
            int num = cur.second+add[d];

            if (step==n) {
                if (is_used[num]) {
                    continue;
                }
                ++count;
                is_used[num]=true;
            }
            else {
                s.push({step,num});
            }
        }
    }
    cout << count;

    return 0;
}
```

* [[BOJ] 로마 숫자 만들기](https://www.acmicpc.net/problem/16922) - 꼬리 재귀를 이용한 DFS
###### Memory: KB, Time: ms
```c++
```

---
|[이전 - BFS & DFS](/bfs_dfs/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Backtracking](/backtracking/)|
|-|-|-|