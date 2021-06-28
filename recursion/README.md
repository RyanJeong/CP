# Recursion
* 자신을 정의할 때 자기 자신을 재참조하는 방법
* 수학적 귀납법에서 사용되는 논리 전개 방식이 재귀 함수 구현에 그대로 적용됨
    * [유한 귀납법](https://namu.wiki/w/%EC%88%98%ED%95%99%EC%A0%81%20%EA%B7%80%EB%82%A9%EB%B2%95#s-1.1)
    > 도미노를 통해 귀납적인 논리 전개 방식을 설명하면:<br>
      1. 첫 번째에 세워져 있는 도미노가 쓰러지는지 확인한다 (base condition).<br>
      2. 무작위로 고른 <i>n</i> 번째에 세워져 있는 도미노가 쓰러질 때, 항상 <i>n+1</i> 번째에 세워져 있는 도미노도 쓰러지는지 확인한다. <br>
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

> 1. `factorial(1)`은 1을 반환한다. 


---
|[이전 - BFS & DFS](/bfs_dfs/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Backtracking](/backtracking/)|
|-|-|-|