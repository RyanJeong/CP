# Tree
* 추천 문제
    * [[BOJ] 트리의 높이와 너비](https://www.acmicpc.net/problem/2250) [(소스코드)](./src/height_and_width.cpp)
---

## 트리
* 사이클이 없는 무방향 그래프(Undirected Acyclic Connected Graph)
> In graph theory, a tree is an undirected graph in which any two vertices are connected by exactly one path, or equivalently a connected acyclic undirected graph.

## 특징
* <b><i>V</i>개의 정점을 가지고 있을 때 간선의 개수는 <i>V</i>-1</b>
* 임의의 간선을 추가하게 되면 사이클이 생성됨
* 임의의 간선을 제거하면 더 이상 연결 그래프가 아님 

## 트리를 사용한 BFS
* 시간복잡도는 <b>O(<i>V</i>+<i>E</i>)</b>

* 트리에서의 순회
    * <b>O(<i>V</i>+<i>E</i>)</b>
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
* 시간복잡도는 <b>O(<i>V</i>+<i>E</i>)</b>

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

### 연습문제
* [[BOJ] 트리의 부모 찾기](https://www.acmicpc.net/problem/11725) [(소스코드)](./src/parent.cpp)
###### Memory: 12,484 KB, Time: 68 ms
```c++
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj_list;
vector<int> parent;

void dfs(int cur);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    adj_list=vector<vector<int>>(n+1);
    parent=vector<int>(n+1);
    for (int i = 1; i<n; ++i) {
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1);
    for (int i = 2; i<=n; ++i) { // E = V-1
        cout << parent[i] << '\n';
    }
    
    return 0;
}

void dfs(int cur)
{
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

### 이진 트리 순회 구현

![exam](./img/exam.png)
```c++
// root: 1
vector<int> parent = {0,0,1,1,2,2,3,3,4,4,5,5,0,6,7};
vector<int> left_child = {0,2,4,6,8,10,0,14,0,0,0,0,0,0,0};
vector<int> right_child = {0,3,5,7,9,11,13,0,0,0,0,0,0,0,0};

void postorder(int cur)
{
    if (left_child[cur]) {
        postorder(left_child[cur]);
    }
    if (right_child[cur]) {
        postorder(right_child[cur]);
    }
    cout << cur << ' ';

    return;
}

void preorder(int cur)
{
    cout << cur << ' ';
    if (left_child[cur]) {
        preorder(left_child[cur]);
    }
    if (right_child[cur]) {
        preorder(right_child[cur]);
    }

    return;
}

void inorder(int cur)
{
    if (left_child[cur]) {
        inorder(left_child[cur]);
    }
    cout << cur << ' ';
    if (right_child[cur]) {
        inorder(right_child[cur]);
    }

    return;
}

int level_order(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur << ' ';
        if (left_child[cur]) {
            q.push(left_child[cur]);
        }
        if (right_child[cur]) {
            q.push(right_child[cur]);
        }
    }

    return;
}
```

### 연습문제
* [[BOJ] 트리 순회](https://www.acmicpc.net/problem/1991) [(소스코드)](./src/tree.cpp)
###### Memory: 2,020 KB, Time: 0 ms
```c++
#include <bits/stdc++.h>

using namespace std;

void preorder(int cur);
void inorder(int cur);
void postorder(int cur);

vector<int> left_child;
vector<int> right_child;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin>>n;
    left_child=vector<int>(n+1);
    right_child=vector<int>(n+1);
    for (int i = 1; i<=n; ++i) {
        char v, lc, rc;
        cin>>v>>lc>>rc;

        v=v-'A'+1;
        if (lc!='.') {
            left_child[v]=lc-'A'+1;
        }
        if (rc!='.') {
            right_child[v]=rc-'A'+1;
        }
    }
    // preorder
    preorder(1);
    cout << '\n';

    // inorder
    inorder(1);
    cout << '\n';

    // postorder
    postorder(1);
    cout << '\n';
    
    return 0;
}

void preorder(int cur)
{
    char c = cur+'A'-1;
    cout << c;
    if (left_child[cur]) {
        preorder(left_child[cur]);
    }
    if (right_child[cur]) {
        preorder(right_child[cur]);
    }

    return;
}

void inorder(int cur)
{
    if (left_child[cur]) {
        inorder(left_child[cur]);
    }
    char c = cur+'A'-1;
    cout << c;
    if (right_child[cur]) {
        inorder(right_child[cur]);
    }

    return;
}

void postorder(int cur)
{
    if (left_child[cur]) {
        postorder(left_child[cur]);
    }
    if (right_child[cur]) {
        postorder(right_child[cur]);
    }
    char c = cur+'A'-1;
    cout << c;

    return;
}
```

---
|[이전 - Graph](/graph/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Topological Sort](/topological_sort/)|
|-|-|-|
