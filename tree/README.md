# Tree
* 추천 문제
    * [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
---

## 트리
* 사이클이 없는 무방향 그래프(Undirected Acyclic Connected Graph)
> In graph theory, a tree is an undirected graph in which any two vertices are connected by exactly one path, or equivalently a connected acyclic undirected graph.

## 특징
* <b><i>V</i>개의 정점을 가지고 있을 때 간선의 개수는 <i>V</i>-1</b>
* 임의의 간선을 추가하게 되면 사이클이 생성됨
* 임의의 간선을 제거하면 더 이상 연결 그래프가 아님 

## 트리를 사용한 BFS
* 트리에서의 순회
    * 해당 정점을 기준으로 자식 정점만 `queue`에 넣고 순회
    * 자식 정점들은 아직 방문 전 상태임을 보장 받음
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);

    void bfs(int root)
    {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';

            for (int next : adj_list[cur]) {
                if (parent[cur]==next) {
                    continue;
                }
                q.push(next);
                parent[next]=cur;
            }
        }

        return;
    }
```

* 트리 순회와 동시에 깊이(depth) 기록
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);
    vector<int> depth(n+1); // init. all to 0

    void bfs(int root)
    {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            cout << cur << ' ';

            for (int next : adj_list[cur]) {
                if (parent[cur]==next) {
                    continue;
                }
                q.push(next);
                parent[next]=cur;
                depth[next]=depth[cur]+1;
            }
        }

        return;
    }
```

## 트리를 사용한 DFS
* 트리에서의 순회 (재귀)
    * <i>V</i>가 많으면(즉, 깊이가 깊다면) stack 영역 메모리 초과가 발생할 수 있음에 유의
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);

    void dfs(int cur)
    {
        cout << cur << ' ';
        for (int next : adj_list[cur]) {
            if (parent[cur]==next) {
                continue;
            }
            parent[next]=cur;
            dfs(next);
        }

        return;
    }
```
```c++
    // opt. version
    vector<vector<int>> adj_list(n+1); // 1-based

    // if root is 1 then:
    dfs(1,0);
    
    ...

    void dfs(int cur, int parent)
    {
        cout << cur << ' ';
        for (int next : adj_list[cur]) {
            if (parent==next) {
                continue;
            }
            dfs(next,cur);
        }

        return;
    }
```

* 트리에서의 순회 (비재귀)
    * 해당 정점을 기준으로 자식 정점만 `stack`에 넣고 순회
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);

    void dfs(int root)
    {
        stack<int> s;
        s.push(root);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            cout << cur << ' ';

            for (int next : adj_list[cur]) {
                if (parent[cur]==next) {
                    continue;
                }
                s.push(next);
                parent[next]=cur;
            }
        }

        return;
    }
```

* 트리 순회와 동시에 깊이(depth) 기록 (재귀)
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);
    vector<int> depth(n+1); // init. all to 0

    void dfs(int cur)
    {
        cout << cur << ' ';
        for (int next : adj_list[cur]) {
            if (parent[cur]==next) {
                continue;
            }
            parent[next]=cur;
            depth[next]=depth[cur]+1;
            dfs(next);
        }

        return;
    }
```

* 트리 순회와 동시에 깊이(depth) 기록 (비재귀)
```c++
    vector<vector<int>> adj_list(n+1); // 1-based
    vector<int> parent(n+1);
    vector<int> depth(n+1); // init. all to 0

    void dfs(int root)
    {
        stack<int> s;
        s.push(root);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            cout << cur << ' ';

            for (int next : adj_list[cur]) {
                if (parent[cur]==next) {
                    continue;
                }
                s.push(next);
                parent[next]=cur;
                depth[next]=depth[cur]+1;
            }
        }

        return;
    }
```

## 이진 트리 순회

![tree](./img/tree.png)

* Postorder traversal
    * DFS 변형
    * 선 순회 <b>후</b> 방문(왼쪽에서 오른쪽으로)

* Preorder traversal
    * 일반적인 DFS
    * 후 순회 <b>선</b> 방문(왼쪽에서 오른쪽으로)

* Inorder traversal
    * 왼쪽 순회, 정점 방문, 오른쪽 순회 순
    * 정점에 기록된 값을 오름차순 순회

* Level-order traversal
    * 일반적인 BFS


### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - Graph](/graph/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Topological Sort](/topological_sort/)|
|-|-|-|
