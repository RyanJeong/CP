* [STL - Container Classes:](/stl/)
    * Sequence Container
        * [Vector](/stl/vector/)
        * [List](/stl/list/)
        * [Double-ended Queue(Deque)](/stl/deque/)
    * Container Adaptor
        * [Stack](/stl/stack/)
        * [Queue](/stl/queue/)
        * [Priority Queue](/stl/priority_queue_heap/)
    * Associative Container
        * [Set](/stl/set/)
        * [Map](/stl/map/)

# [Priority Queue](https://cplusplus.com/reference/queue/priority_queue/)
* 힙(heap): 최대값 또는 최소값을 빠르게 찾아내기 위한 이진 트리이며, <b>이진 탐색 트리가 아님에 유의할 것</b>
* STL에서 제공하는 힙은 `priority_queue`이며, 최대힙을 나타냄
* 최소값 또는 최대값을 확인하는 것이 목적이라면, 균형 이진 트리를 통해서도 해를 구할 수 있지만 힙을 사용하는 것이 더 유리함
    * 균형 이진 트리를 사용하는 것보다 힙을 사용하는 것이 메모리를 적게 차지하고 동작 속도도 더 빠름

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    priority_queue<int> pq;
    for (int i = 0; i<10; ++i) {
        pq.push(rand()%100);
    }
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
        /*
            93
            92
            86
            86
            83
            77
            49
            35
            21
            15
        */
    }

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|