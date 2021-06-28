# Recursion
* 자신을 정의할 때 자기 자신을 재참조하는 방법
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
> 
1. `factorial(1)`은 1을 반환한다. 
---
|[이전 - BFS & DFS](/bfs_dfs/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Backtracking](/backtracking/)|
|-|-|-|