# [서로소 집합(Disjoint-set)](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)

## 서로소 집합
* 추천 문제
    * [[BOJ] Gates](https://www.acmicpc.net/problem/10775) [(소스코드)](./src/gate.cpp) - Rank(level)를 사용하지 않고 조건에 맞게 `union` 수행
    * [[BOJ] Virtual Friends](https://www.acmicpc.net/problem/4195) [(소스코드)](./src/virtual_friend.cpp) - `hash` 사용
    * [[BOJ] 비용](https://www.acmicpc.net/problem/2463) [(소스코드)](./src/cost.cpp) - 거꾸로 생각하기!
    * [[WIP][BOJ] Never Wait for Weights](https://www.acmicpc.net/problem/3830) [(소스코드)](./src/weight.cpp)
    * [[BOJ] LADICE](https://www.acmicpc.net/problem/9938) [(소스코드)](./src/ladice.cpp) - Rank(level) compression을 사용하지 않고, 방문 여부에 따라 `union`을 수행


* 서로소(disjoint)
    * 공통으로 포함하는 원소가 없는 두 집합의 관계

* 합집합-찾기(union–find) 또는 병합-찾기 집합(merge–find set)으로도 불림
* 많은 서로소 부분 집합들로 나눠진 원소들에 대한 정보를 저장하고 조작하는 트리 형태의 자료 구조
* `A ∩ B = 0, (A, B ⊂ C)`

## 연산
* <i>find</i>
    * 어떤 원소가 주어졌을 때, 이 원소가 속한 집합 반환
    * <i>find</i>는 일반적으로 어떤 원소가 속한 집합을 <b>대표</b>하는 원소(트리에서의 root)를 반환
    * 어떤 원소와 각 대표 원소들 간의 <i>find</i> 결과를 비교하여 같은 집합임을 판단
* <i>union</i>
    * 두 개의 집합을 하나의 집합으로 병합

## 구현
1. 초기화 - 시간복잡도와 공간복잡도는 <b>O(<i>n</i>)</b>
```c++
    int find(int);
    void merge(int, int);

    int n;
    cin>>n;
    vector<int> parent(n), level(n,1);
    for (int i = 0; i<n; ++i) {
        parent[i]=i;
    }
```

2. <i>find</i> - 시간복잡도와 공간복잡도는 <b>O(<i>α</i>(<i>n</i>))</b>
    * <i>α</i>(<i>n</i>)은 [inverse Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function#Inverse)이며, <i>α</i>(<i>n</i>)에서 <i>n</i>의 값이 2<sup>65,536</sup>일 때 결과는 약 5가 된다. 즉 일반적인 상황에서의 <b>O(<i>α</i>(<i>n</i>))</b>은 <b>O(1)</b>로 간주된다. 
```c++
int find(int u)
{
    if (u==parent[u]) {
        
        return u;
    }

    // path compression
    return parent[u]=find(parent[u]);
}
```

3. <i>union</i> - 시간복잡도와 공간복잡도는 <b>O(<i>α</i>(<i>n</i>))</b>    
```c++
void merge(int u, int v) 
{ 
    u=find(u); 
    v=find(v); 
    // 1. 부모가 같을 경우
    if (u==v) {
        
        return; 
    }
    // 2. 깊이가 다를 경우, 더 깊은 집합에 속하도록 함
    if (level[u]>level[v]) {
        swap(u,v); 
    }
    parent[u]=v;
    // 3. 두 트리의 높이가 같다면, 해당 트리의 level 1 증가
    if (level[u]==level[v]) {
        ++level[v]; 
    }

    return;
}
```

### 연습문제
* [[BOJ] 집합의 표현](https://www.acmicpc.net/problem/1717) [(소스코드)](./src/set.cpp)
```c++
// https://www.acmicpc.net/problem/1717
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int m;
    cin>>m;
    for (int i = 0; i<=n; ++i) {
        parent.push_back(i);
        level.push_back(1);
    }
    for (int i = 0; i<m; ++i) {
        int c;
        cin>>c;
        int u;
        cin>>u;
        int v;
        cin>>v;
        if (!c) { // union
            merge(u,v);
        }
        else { // find
            cout << ((find(u)==find(v)) ? "YES" : "NO") << '\n';
        }
    }

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

* [[BOJ] 여행 가자](https://www.acmicpc.net/problem/1976) [(소스코드)](./src/travel.cpp)
```c++
// https://www.acmicpc.net/problem/1976
#include <bits/stdc++.h>

using namespace std;

int find(int);
void merge(int, int);

vector<int> parent, level;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;

    parent = vector<int>(n+1);
    level = vector<int>(n+1,1);
    for (int i = 1; i<=n; ++i) {
        parent[i]=i;
    }
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=n; ++j) {
            int temp;
            cin>>temp;
            if (temp) {
                merge(i,j);
            }
        }
    }

    vector<int> path(m+1);
    for (int i = 1; i<=m; ++i) {
        cin>>path[i];
    }
    bool is_linked=true;
    for (int i = 1; i<m; ++i) {
        if (find(path[i])!=find(path[i+1])) {
           is_linked=false;
           break;
        }
    }
    cout << ((is_linked) ? "YES" : "NO") << '\n';

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

---
|[이전 - String](/string/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Mathematics:](/math/)
|-|-|-|