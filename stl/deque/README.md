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

# [Double-ended Queue(Deque)](https://www.cplusplus.com/reference/deque/deque/)
* `deque` (usually pronounced like "deck") is an irregular acronym of <b>d</b>ouble-<b>e</b>nded <b>que</b>ue.
* Restricted Structure
* `push`의 시간 복잡도는 <b><i>O</i>(1)</b>
* `pop`의 시간 복잡도는 <b><i>O</i>(1)</b>
* `front`, `back`의 시간 복잡도는 <b><i>O</i>(1)</b>

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;
    dq.push_back(10);  // { 10 }
    dq.push_back(40);  // { 10 40 }
    dq.push_front(50); // { 50 10 40 }
    cout << dq.size() << '\n';  // 3
    cout << dq.front() << '\n'; // 50
    cout << dq.back() << '\n';  // 40
    if (dq.empty()) {
        cout << "Deque is empty!\n";
    } 
    else {
        cout << "Deque is not empty!\n"; // print "Deque is not empty!"
    }
    dq.pop_front();   // { 10 40 }
    dq.push_back(60); // { 10 40 60 }
    dq.pop_back();    // { 10 40 }
    cout << dq.front() << '\n'; // 10
    cout << dq.back() << '\n';  // 40
    for (int i : dq) {
        cout << i << ' '; // 10 40
    }
    cout << '\n';

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|