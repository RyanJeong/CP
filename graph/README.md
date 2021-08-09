# Graph
* 추천 문제
    * [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
---

## 그래프
* 기본 용어
    * 정점(Vertex, Node): 그래프를 구성하는 요소중의 하나로 연결점
    * 간선(Edge): 두 정점 간을 이어주는 선분
    * 차수(Degree): 정점에 연결된 간선 개수
    * 무방향 그래프(Undirected Graph): 간선에 방향성이 없는 경우
    * 방향 그래프(Directed Graph) 간선에 방향성이 있는 경우
        * Outdegree: 해당 정점으로부터 나가는 간선의 수
        * Indegree: 해당 정점으로부터 들어오는 간선의 수
    * 순환 그래프(Cyclic Graph): 임의의 한 정점으로부터 출발해 자기 자신으로 돌아올 수 있는 경로(cycle)가 존재하는 그래프
    * 비순환 그래프(Acyclic Graph): 임의의 한 정점으로부터 출발해 자기 자신으로 돌아올 수 있는 경로가 존재하지 않는 그래프
    * 완전 그래프(Complete Graph): 모든 서로 다른 두 정점 쌍이 간선으로 연결된 그래프
    * 연결 그래프(Connected Graph): 임의의 두 정점 사이에 경로가 존재하는 그래프
    * 단순 그래프(Simple Graph): 임의의 두 정점 사이에 오직 1개의 간선만이 연결되어 있는 그래프

* 표현
    * 인접 행렬(Adjacency Matrix)
        * 총 정점 수가 <i>V</i>일 때, 공간복잡도는 <b>O(<i>V</i><sup>2</sup>)</b>
        * 정점 연결 상태 확인 시 시간복잡도는 <b>O(1)</b>
        * 어떤 정점에 연결되어 있는 정점들을 확인하고자 할 때의 시간복잡도는 <b>O(<i>V</i>)</b>

        ![adjacenty_matrix](./img/Adjacency_matrix_for_graph.png)

        * 무방향 그래프를 인접 행렬로 표현 시 대칭 형태를 나타냄
        * 방향 그래프를 인접 행렬로 표현하면 행은 출발 정점, 열은 도착 정점을 나타냄
        ```c++
        // n X m directed graph
        vector<vector<int>> adj_matrix(n+1,vector(m+1)); // 1-based

        int e;
        cin>>e;
        for (int i = 1; i<=e; ++i) {
            int u, v;
            cin>>u>>v;
            adj_matrix[u][v]=1;
        }

        // n X m undirected graph
        vector<vector<int>> adj_matrix(n+1,vector(m+1)); // 1-based

        int e;
        cin>>e;
        for (int i = 1; i<=e; ++i) {
            int u, v;
            cin>>u>>v;
            adj_matrix[u][v]=1;
            adj_matrix[v][u]=1;
        }
        ```

    * 인접 리스트(Adjacency Lists)
        * 총 정점 수가 <i>V</i>, 총 간선 수가 <i>E</i>일 때, 공간복잡도는 <b>O(<i>V</i>+<i>E</i>)</b>
            * <i>V</i>가 크면서 상대적으로 <i>E</i>가 작을 경우 공간을 절약할 수 있음
            * 모든 리스트에서의 원소 개수는 방향 그래프일 경우 <i>E</i>개, 무방향 그래프일 경우 2<i>E</i>개
        * 어떤 정점에 연결되어 있는 정점들을 확인하고자 할 때, 해당 정점에 연결된 리스트의 수만큼만 순회하면 결과를 얻을 수 있음 (<b>O(dev(<i>V</i>))</b>)

        ![adjacenty_lists_a](./img/Adjacency_lists_a.gif)
        ![adjacenty_lists_b](./img/Adjacency_lists_b.gif)

        ```c++
        // n X m directed graph
        vector<int> adj_list(n+1); // 1-based

        int e;
        cin>>e;
        for (int i = 1; i<=e; ++i) {
            int u, v;
            adj_list[u].push_back(v);
        }

        // n X m undirected graph
        vector<int> adj_list(n+1); // 1-based

        int e;
        cin>>e;
        for (int i = 1; i<=e; ++i) {
            int u, v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        ```
    
    * 비교

    ![compare](./src/compare.jpg)


### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - String](/string/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Tree](/tree/)|
|-|-|-|
