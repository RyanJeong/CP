# Backtracking
* 추천 문제
    * [[BOJ] N-Queen](https://www.acmicpc.net/problem/9663) [(소스코드)](./src/n_queen.cpp)
    * [[BOJ] 비숍](https://www.acmicpc.net/problem/1799) [(소스코드)](./src/210618_bishop.cpp)
    * [[BOJ] Sudoku](https://www.acmicpc.net/problem/2239) [(소스코드)](./src/210712_sudoku.cpp)

## 백트래킹
* DFS(재귀)의 응용
* Go as deeply as possible, backtrack if impossible

### 연습문제
* [[BOJ] N과 M (1)](https://www.acmicpc.net/problem/15649) [(소스코드)](./src/n_m.cpp)
###### Memory: 2,016 KB, Time: 24 ms
```c++
// https://www.acmicpc.net/problem/15649
#include <bits/stdc++.h>

using namespace std;

void bt(int);

int n, m;
int arr[9]; // 0, 1 ~ 8
bool is_used[9];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    bt(0);

    return 0;
}

void bt(int s)
{
    if (s==m) {
        for (int i = 0; i<m; ++i) {
            cout << arr[i] << ' ';
        }
        cout <<'\n';

        return;
    }
    for (int i = 1; i<=n; ++i) {
        if (!is_used[i]) {
            arr[s]=i;
			// Go as deeply as possible, backtrack if impossible
            is_used[i]=true;
            bt(s+1);
            is_used[i]=false;
        }
    }

    return;
}
```

---
|[이전 - Recursion](/recursion/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Dynamic Programming](/dp/)|
|-|-|-|