# Topological Sort
* 추천 문제
    * [[BOJ] 음악프로그램](https://www.acmicpc.net/problem/2623) [(소스코드)](./src/music_program.cpp) - 위상 정렬 후 DAG 여부 확인
    * [[BOJ] ACM Craft](https://www.acmicpc.net/problem/1005) [(소스코드)](./src/acm_craft.cpp) - 위상 정렬 + DP
    * [[BOJ] 게임 개발](https://www.acmicpc.net/problem/1516) [(소스코드)](./src/game.cpp) - 위상 정렬 + DP
---

## 위상 정렬
* 방향 그래프 중 정점 간 선후관계를 위배하지 않도록 정렬
    * 그래프 내에 사이클이 존재할 경우 위상 정렬을 할 수 없음
    * 위상 정렬을 하기 위해서는 그래프가 사이클이 없는 방향 그래프(Directed Acyclic Graph)여야 함

![topological_sort](./img/topological_sort.png)

## 방법
* 정점에서의 Indegree를 검사해 해당 정점에서의 Indegree가 0이라면 정렬 결과에 기록하고 해당 정점으로부터 나가는 간선들(Outdegree)에 연결된 정점들의 Indegree를 1 감소
    * 사이클이 존재하지 않는 유향그래프(DAG)이므로, 정렬 시 적어도 정점 하나의 Indegree는 0
* 모든 정점을 순회해 결과를 기록할 때까지 반복
* 시간복잡도는 <b>O(<i>V</i>+<i>E</i>)</b>
```c++
vector<vector<int>> adj_list(n+1);
vector<int> indegree(n+1);

void topological_sort(int n)
{
    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (int next : adj_list[cur]) {
            --indegree[next];
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }

    if (res.size()!=n) {
        cout << "This graph is not DAG";

        exit(1);
    }
    for (int i : res) {
        cout << i << ' ';
    }

    return;
}
```

### 연습문제
* [[BOJ] 줄 세우기](https://www.acmicpc.net/problem/2252) [(소스코드)](./src/line_up.cpp)
###### Memory: 4,216 KB, Time: 28 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj_list(n+1);
    vector<int> indegree(n+1);
    for (int i = 1; i<=m; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        ++indegree[v];
    }

    queue<int> q;
    for (int i = 1; i<=n; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }
    vector<int> res;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);

        for (int next : adj_list[cur]) {
            --indegree[next];
            if (!indegree[next]) {
                q.push(next);
            }
        }
    }
    for (int i : res) {
        cout << i << ' ';
    }
    
    return 0;
}
```

---
|[이전 - Tree](/tree/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Disjoint-set](/disjoint-set/)|
|-|-|-|