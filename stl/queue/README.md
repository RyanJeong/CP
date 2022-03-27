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

# [WIP]Queue
* 추천 문제
    * [[BOJ] 이름 궁합](https://www.acmicpc.net/problem/15312) [(소스코드)](./src/name.cc) - 기본 큐 연산 및 초기화 방법
    * [[Programmers] 프린터](https://programmers.co.kr/learn/courses/30/lessons/42587) [(소스코드)](./src/printer.cc)
    * [[BOJ] 큐](https://www.acmicpc.net/problem/10845) [(소스코드)](./src/queue.cc)
    * [[BOJ] 카드2](https://www.acmicpc.net/problem/2164) [(소스코드)](./src/card2.cc)
    * [[BOJ] 좀비 떼가 기관총 진지에도 오다니](https://www.acmicpc.net/problem/19644) [(소스코드)](./src/zombie.cc) - 조건의 범위를 검사할 때 `queue` 사용
---

## [큐(queue)](https://cplusplus.com/reference/queue/queue/)
* Restricted Structure
* FILO (First In Last Out)
* `push`의 시간 복잡도는 <b>O(1)</b>
* `pop`의 시간 복잡도는 <b>O(1)</b>
* `front`, `back`의 시간 복잡도는 <b>O(1)</b>

### [소스코드](./src/exam.cc)
```c++
#include <iostream>
#include <queue>

// iostream
using std::cin;
using std::cout;

// queue
using std::queue;

int main() {
  queue<int> q;

  q.push(10);                // { 10 }
  q.push(20);                // { 10 20 }
  q.push(30);                // { 10 20 30 }
  cout << q.size() << '\n';  // 3
  if (q.empty())
    cout << "Queue is empty!\n";
  else
    cout << "Queue is not empty!\n";  // print "Queue is not empty!"
  cout << q.front() << '\n';  // 10
  cout << q.back() << '\n';   // 30
  q.pop();                    // { 20 30 }
  q.push(40);                 // { 20 30 40 }
  cout << q.front() << '\n';  // 20
  cout << q.back() << '\n';   // 40

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|