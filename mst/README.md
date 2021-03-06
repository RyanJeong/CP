# Minimum Spanning Tree
* 추천 문제
    * [[BOJ] Freckles](https://www.acmicpc.net/problem/4386) [(소스코드)](./src/freckle.cpp) - 크루스칼 + 소수점 표현
    * [[BOJ] 네트워크 연결](https://www.acmicpc.net/problem/1922) [(소스코드)](./src/network.cpp) - 크루스칼, 루프 제거
    * [[BOJ] Dark roads](https://www.acmicpc.net/problem/6497) [(소스코드)](./src/dark_road.cpp) - 크루스칼, 0-based
    * [[BOJ] 다리 만들기 2](https://www.acmicpc.net/problem/17472) [(소스코드)](./src/bridge.cpp) - Flood Fill + 크루스칼
---

## 최소 신장 트리(MST)
* 신장 트리(Spanning Tree)
    * 트리는 사이클이 없는 무방향 그래프(Undirected Acyclic Connected Graph)
    * 트리 <i>T</i>가 그래프 <i>G</i>의 모든 정점을 포함하는 부분 그래프이자 트리라면, <i>T</i>는 <i>G</i>의 신장 트리
    * 트리의 성질에 의해 그래프의 정점이 <i>V</i>개라면, 신장 트리는 <i>V</i>-1 개의 간선을 갖게 됨

* 최소 신장 트리(Minimum Spanning Tree)
    * 신장 트리 중에서 간선의 합이 최소인 트리
    * 신장 트리를 구할 수 있는 알고리즘은 크루스칼 알고리즘과 프림 알고리즘이 있음

![MST](./img/mst.png)

## 크루스칼 알고리즘(Kruskal's algorithm)
* 간선의 비용을 오름차순으로 정렬해 가장 낮은 비용의 간선을 선택
* 선택한 간선의 두 정점이 같은 그룹이라면 다음 간선을 선택하고, 그렇지 않다면 두 정점을 같은 그룹으로 묶은 뒤 해당 간선을 최소 신장 트리에 추가함
* 최소 신장 트리에 추가된 간선의 개수가 <i>V</i>-1 개가 될 때까지 위 과정 반복
* 시간복잡도는 <b>O(<i>E</i> log <i>E</i>)</b>

![kruskal1](./img/kruskal1.png)

![kruskal2](./img/kruskal2.png)

### 연습문제
* [[BOJ] 최소 스패닝 트리](https://www.acmicpc.net/problem/1197) [(소스코드)](./src/kruskal.cpp) - 크루스칼 알고리즘 사용
```c++
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    parent=vector<int>(v+1);
    level=vector<int>(v+1,1);
    for (int i = 0; i<=v; ++i) {
        parent[i]=i;
    }
    vector<pair<int, pair<int, int>>> edge(e);
    for (int i = 0; i<e; ++i) {
        cin>>edge[i].second.first>>edge[i].second.second>>edge[i].first;
    }
    sort(edge.begin(),edge.end());
    
    int cnt = 0;
    int res = 0;
    for (int i = 0; i<e; ++i) {
        int cost = edge[i].first;
        int v1 = edge[i].second.first;
        int v2 = edge[i].second.second;

        if (find(v1)==find(v2)) {
            continue;
        }
        merge(v1,v2);
        res+=cost;
        ++cnt;
        if (cnt==v-1) {
            break;
        }
    }
    cout << res;

    return 0;
}

int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }

    return parent[u]=find(parent[u]);
}

void merge(int u, int v)
{
    u=find(u); 
    v=find(v); 
    if (u==v) {
        
        return; 
    }
    if (level[u]>level[v]) {
        swap(u,v); 
    }
    parent[u]=v;
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return;
}
```

## 프림 알고리즘(Prim's algorithm)
* 임의의 정점을 선택해 최소 신장 트리에 추가하고, 해당 정점과 연결된 모든 간선을 `heap`에 추가함
* `heap`에서 비용이 가장 작은 간선을 꺼냄
    * 만약 해당 간선이 최소 신장 트리에 포함되어 있는 두 정점을 연결한다면 다음 간선을 꺼냄
    * 만약 해당 간선이 최소 신장 트리에 포함되어 있는 정점 <i>u</i>와 포함되지 않은 정점 <i>v</i>를 연결한다면, <i>v</i>를 최소 신장 트리에 추가함
* 최소 신장 트리에 추가된 간선의 개수가 <i>V</i>-1 개가 될 때까지 위 과정 반복
* 시간복잡도는 <b>O(<i>E</i> log <i>E</i>)</b>

![prim1](./img/prim1.png)

![prim2](./img/prim2.png)

![prim3](./img/prim3.png)

### 연습문제
* [[BOJ] 최소 스패닝 트리](https://www.acmicpc.net/problem/1197) [(소스코드)](./src/prim.cpp) - 프림 알고리즘 사용
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;
    vector<vector<pair<int, int>>> adj_list(v+1);
    for (int i = 1; i<=e; ++i) {
        int a, b, c;
        cin>>a>>b>>c;
        adj_list[a].push_back({c,b});
        adj_list[b].push_back({c,a});
    }

    // cost, u, v
    priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
    vector<bool> is_used(v+1);
    is_used[1]=true;
    for (auto next : adj_list[1]) {
        pq.push({next.first,make_pair(1,next.second)});
    }

    int cnt = 0;
    int res = 0;
    while (1) {
        auto cur = pq.top();
        pq.pop();

        int cost = cur.first;
        // int v1 = cur.second.first; // optional
        int v2 = cur.second.second;
        if (is_used[v2]) {
            continue;
        }

        is_used[v2]=true;
        res+=cost;
        ++cnt;
        if (cnt==v-1) {
            break;
        }
        for (auto next : adj_list[v2]) {
            if (!is_used[next.second]) {
                pq.push({next.first,make_pair(v2,next.second)});
            }
        }
    }
    cout << res;
    
    return 0;
}
```

---
|[이전 - Disjoint-set](/disjoint-set/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Floyd-Warshall](/floyd-warshall/)|
|-|-|-|