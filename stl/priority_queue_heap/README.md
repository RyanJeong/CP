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

# [WIP]Priority Queue
* 추천 문제
  * [[BOJ] 최대 힙](https://www.acmicpc.net/problem/11279) [(소스코드)](./src/max_heap.cc) - `priority_queue<T>`
  * [[BOJ] 최소 힙](https://www.acmicpc.net/problem/1927) [(소스코드)](./src/min_heap.cc) - `priority_queue<T, vector<T>, greater<T>>`
  * [[BOJ] Running Median](https://www.acmicpc.net/problem/2696) [(소스코드)](./src/median.cpp)
  * [[BOJ] N번째 큰 수](https://www.acmicpc.net/problem/2075) [(소스코드)](./src/nth.cpp)
  * [[BOJ] 강의실 배정](https://www.acmicpc.net/problem/11000) [(소스코드)](./src/210710_class.cpp)
  * [[BOJ] 싸지방에 간 준하](https://www.acmicpc.net/problem/12764) [(소스코드)](./src/army_internet_cafe.cpp) 
  * [[BOJ] 강의실 배정](https://www.acmicpc.net/problem/11000) 응용, 각 객체의 사용빈도를 같이 구해야 하는 문제
  * [[BOJ] 문제집](https://www.acmicpc.net/problem/1766) [(소스코드)](./src/210721_textbook.cpp)
  * [[BOJ] 화장실의 규칙](https://www.acmicpc.net/problem/19640) [(소스코드)](./src/210710_restroom.cpp) - 비교연산 직접 구현한 예
  * [[BOJ] 문제 추천 시스템 Version 1](https://www.acmicpc.net/problem/21939) [(소스코드)](./src/recommendation1.cpp) - 힙 중간 요소를 제거해야 할 경우
  * [[BOJ] Supermarket](https://www.acmicpc.net/problem/2109) [(소스코드)](./src/supermarket.cpp) - 그리디, 우선 순위 큐에 조건을 만족하는 요소를 넣은 뒤, 요소의 크기가 범위를 넘어가면 가장 작은 요소부터 차례대로 제거
---

## [우선 순위 큐(priority queue of heap)](https://cplusplus.com/reference/queue/priority_queue/)
* 힙(heap): 최대값 또는 최소값을 빠르게 찾아내기 위한 이진 트리이며, <b>이진 탐색 트리가 아님에 유의할 것</b>
* STL에서 제공하는 힙은 `priority_queue`이며, 최대힙을 나타냄
* 최소값 또는 최대값을 확인하는 것이 목적이라면, 균형 이진 트리를 통해서도 해를 구할 수 있지만 힙을 사용하는 것이 더 유리함
    * 균형 이진 트리를 사용하는 것보다 힙을 사용하는 것이 메모리를 적게 차지하고 동작 속도도 더 빠름
* Note that the [<i>Compare</i>](https://en.cppreference.com/w/cpp/named_req/Compare) parameter is defined such that it returns `true` if its first argument comes <i>before</i> its second argument in a <b>weak ordering</b>. But because the priority queue outputs largest elements first, <b>the elements that "come before" are actually output last</b>. That is, the front of the queue contains the "last" element according to the weak ordering imposed by [<i>Compare</i>](https://en.cppreference.com/w/cpp/named_req/Compare).

### [소스코드](./src/exam.cpp)
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
### 연습문제
* [[BOJ] 최대 힙](https://www.acmicpc.net/problem/11279) [(소스코드)](./src/exer1.cpp)
```c++
// https://www.acmicpc.net/problem/11279
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    // https://en.cppreference.com/w/cpp/container/priority_queue 
    // priority_queue<int, vector<int>, greater<int>> -> min heap
    // priority_queue<int> -> max heap
    priority_queue<int> max_heap;

    while (n--) {
        int x;
        cin >> x;

        if (!x) {
            if (max_heap.empty()) {
                cout << "0\n";
            } 
            else {
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        } 
        else {
            max_heap.push(x);
        }
    }

    return 0;
}
```

* [[BOJ] 최소 힙](https://www.acmicpc.net/problem/1927) [(소스코드)](./src/exer2.cpp)
```c++
// https://www.acmicpc.net/problem/1927
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    // https://en.cppreference.com/w/cpp/container/priority_queue 
    // priority_queue<int, vector<int>, greater<int>> -> min heap
    // priority_queue<int> -> max heap
    priority_queue<int, vector<int>, greater<int>> min_heap;

    while (n--) {
        int x;
        cin >> x;

        if (!x) {
            if (min_heap.empty()) {
                cout << "0\n";
            } 
            else {
                cout << min_heap.top() << '\n';
                min_heap.pop();
            }
        } 
        else {
            min_heap.push(x);
        }
    }

    return 0;
}
```

* [[BOJ] 절댓값 힙](https://www.acmicpc.net/problem/11286) [(소스코드)](./src/exer3.cpp) - 기본 자료형이 아닌 형에서의 최소 힙
```c++
// https://www.acmicpc.net/problem/11286
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> min_heap;

    while (n--) {
        int x;
        cin >> x;

        if (!x) {
            if (min_heap.empty()) {
                cout << "0\n";
            } 
            else {
                cout << min_heap.top().second << '\n';
                min_heap.pop();
            }
        } 
        else {
            min_heap.push({abs(x),x});
        }
    }

    return 0;
}
```

* 직접 비교 연산자를 구현한 예 [(소스코드)](./src/exer4.cpp)
```c++
// 비교 대상은 node class에서의 value임
#include <bits/stdc++.h>

using namespace std;

struct node {
    int from;
    int to;
    int value;
};

struct cmp_less {
    bool operator()(node s, node t)
    {

        return s.value<t.value;
    }
};

struct cmp_greater {
    bool operator()(node s, node t)
    {

        return s.value>t.value;
    }
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<node, vector<node>, cmp_less> max_heap;
    priority_queue<node, vector<node>, cmp_greater> min_heap;

    max_heap.push({1,1,4});
    max_heap.push({1,2,1});
    max_heap.push({2,1,3});
    max_heap.push({1,3,5});
    max_heap.push({3,3,2});
    cout << "{ " << max_heap.top().from << ", "
         << max_heap.top().to << ", "
         << max_heap.top().value << " }\n"; // { 1, 3, 5 }

    min_heap.push({1,1,4});
    min_heap.push({1,2,1});
    min_heap.push({2,1,3});
    min_heap.push({1,3,5});
    min_heap.push({3,3,2});
    cout << "{ " << min_heap.top().from << ", "
         << min_heap.top().to << ", "
         << min_heap.top().value << " }\n"; // { 1, 2, 1 }

    return 0;
}
```

* [[BOJ] 가운데를 말해요](https://www.acmicpc.net/problem/1655) [(소스코드)](./src/exer5.cpp) - 최소 힙과 최대 힙을 활용한 중앙값 출력 문제
    * 조건:
    1. `max_heap.size()>=min_heap.size()`
    2. `if max_heap.top()>min_heap.top() then swap`
    * 두 조건을 만족한다면, 중앙값은 `max_heap.top()`

    |input|execute|max_heap|min_heap|median|
    |:---:|-------|-------:|-------:|:----:|
    |1|insert to `max_heap`|`1`|`⠀`|1|
    |4|insert to `min_heap`|`1`|`4`|1|
    |6|insert to `max_heap`<br>swap|`6` `1`<br>`4` `1`|`4`<br>`6`|<br>4|

```c++
// https://www.acmicpc.net/problem/1655
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for (int i = 1; i<=n; ++i) {
        int temp;
        cin>>temp;
        if (max_heap.size()<=min_heap.size()) {
            max_heap.push(temp);
        }
        else {
            min_heap.push(temp);
        }
        if (!max_heap.empty() && !min_heap.empty() && max_heap.top()>min_heap.top()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        cout << max_heap.top() << '\n';
    }

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|