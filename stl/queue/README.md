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

# [Queue](https://cplusplus.com/reference/queue/queue/)
* 추천 문제
    * [[BOJ] 큐](https://www.acmicpc.net/problem/10845) [(소스코드)](./src/queue.cpp)
    * [[BOJ] 카드2](https://www.acmicpc.net/problem/2164) [(소스코드)](./src/card2.cpp)
* Restricted Structure
* FILO (First In Last Out)
* `push`의 시간 복잡도는 <b>O(1)</b>
* `pop`의 시간 복잡도는 <b>O(1)</b>
* `front`, `back`의 시간 복잡도는 <b>O(1)</b>

### [소스코드](./src/exam.cpp)
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    q.push(10); // { 10 }
    q.push(20); // { 10 20 } 
    q.push(30); // { 10 20 30 }
    cout << q.size() << '\n'; // 3
    if (q.empty()) {
        cout << "Queue is empty!\n";
    } 
    else {
        cout << "Queue is not empty!\n"; // print "Queue is not empty!"
    }
    cout << q.front() << '\n'; // 10
    cout << q.back() << '\n';  // 30
    q.pop();    // { 20 30 }
    q.push(40); // { 20 30 40 }
    cout << q.front() << '\n'; // 20
    cout << q.back() << '\n';  // 40

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|