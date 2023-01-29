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
  * [[BOJ] Running Median](https://www.acmicpc.net/problem/2696) [(소스코드)](./src/median.cc)
  * [[BOJ] N번째 큰 수](https://www.acmicpc.net/problem/2075) [(소스코드)](./src/nth.cc)
  * [[BOJ] 강의실 배정](https://www.acmicpc.net/problem/11000) [(소스코드)](./src/class.cc)
  * [[BOJ] 싸지방에 간 준하](https://www.acmicpc.net/problem/12764) [(소스코드)](./src/army_internet_cafe.cc) 
  * [[BOJ] 강의실 배정](https://www.acmicpc.net/problem/11000) [(소스코드)](./src/classroom.cc) - 응용, 각 객체의 사용빈도를 같이 구해야 하는 문제
  * [[BOJ] 문제집](https://www.acmicpc.net/problem/1766) [(소스코드)](./src/textbook.cc)
  * [[BOJ] 화장실의 규칙](https://www.acmicpc.net/problem/19640) [(소스코드)](./src/210710_restroom.cc) - 비교연산 직접 구현한 예
  * [[BOJ] 문제 추천 시스템 Version 1](https://www.acmicpc.net/problem/21939) [(소스코드)](./src/recommendation1.cc) - 힙 중간 요소를 제거해야 할 경우
  * [[BOJ] Supermarket](https://www.acmicpc.net/problem/2109) [(소스코드)](./src/supermarket.cc) - 그리디, 우선 순위 큐에 조건을 만족하는 요소를 넣은 뒤, 요소의 크기가 범위를 넘어가면 가장 작은 요소부터 차례대로 제거
---

## [우선 순위 큐(priority queue of heap)](https://cplusplus.com/reference/queue/priority_queue/)
* 힙(heap): 최대값 또는 최소값을 빠르게 찾아내기 위한 이진 트리이며, <b>이진 탐색 트리가 아님에 유의할 것</b>
```cpp
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;
```
* Note that the [<i>Compare</i>](https://en.cppreference.com/w/cpp/named_req/Compare) parameter is defined such that it returns `true` if its first argument comes <i>before</i> its second argument in a <b>weak ordering</b>. But because the priority queue outputs largest elements first, <b>the elements that "come before" are actually output last</b>. That is, the front of the queue contains the "last" element according to the weak ordering imposed by [<i>Compare</i>](https://en.cppreference.com/w/cpp/named_req/Compare).

* STL에서 제공하는 힙은 `priority_queue`이며, 최대힙을 나타냄
```cpp
// https://en.cppreference.com/w/cpp/container/priority_queue 

std::priority_queue<int> max_heap;
// std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;

std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
```

* 최소값 또는 최대값을 확인하는 것이 목적이라면, 균형 이진 트리를 통해서도 해를 구할 수 있지만 힙을 사용하는 것이 더 유리함
  * 균형 이진 트리를 사용하는 것보다 힙을 사용하는 것이 메모리를 적게 차지하고 동작 속도도 더 빠름

### [소스코드](./src/exam.cc)
```c++
#include <iostream>
#include <cstdlib>
#include <queue>

int main() {
  std::priority_queue<int> pq;
  for (int i = 0; i < 10; ++i)
    pq.push(std::rand() % 100);

  while (!pq.empty()) {
    std::cout << pq.top() << '\n';
    pq.pop();
    /*
      93
      92
      86
      86
      83
      ...
    */
  }

  return 0;
}

```
### 연습문제
* [[BOJ] 최대 힙](https://www.acmicpc.net/problem/11279) [(소스코드)](./src/exer1.cc)
```c++
#include <iostream>
#include <queue>

int main() {
  int n;
  std::cin >> n;
  std::priority_queue<int> max_heap;

  while (n--) {
    int x;
    std::cin >> x;

    if (!x) {
      if (max_heap.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << max_heap.top() << '\n';
        max_heap.pop();
      }
    } else {
      max_heap.push(x);
    }
  }

  return 0;
}

```

* [[BOJ] 최소 힙](https://www.acmicpc.net/problem/1927) [(소스코드)](./src/exer2.cc)
```c++
#include <iostream>
#include <queue>

int main() {
  int n;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

  while (n--) {
    int x;
    std::cin >> x;

    if (!x) {
      if (min_heap.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << min_heap.top() << '\n';
        min_heap.pop();
      }
    } else {
      min_heap.push(x);
    }
  }

  return 0;
}

```

* [[BOJ] 절댓값 힙](https://www.acmicpc.net/problem/11286) [(소스코드)](./src/exer3.cc) - 기본 자료형이 아닌 형에서의 최소 힙
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <cmath>

int main() {
  int n;
  std::cin >> n;
  // too much text to fit on one line:
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> min_heap;

  while (n--) {
    int x;
    std::cin >> x;

    if (!x) {
      if (min_heap.empty()) {
        std::cout << "0\n";
      } else {
        std::cout << min_heap.top().second << '\n';
        min_heap.pop();
      }
    } else {
      min_heap.push({std::abs(x), x});
    }
  }

  return 0;
}

```

* 직접 비교 연산자를 구현한 예 [(소스코드)](./src/exer4.cc)
```c++
#include <iostream>
#include <queue>

// 비교 대상은 Node의 value
struct Node {
  int from;
  int to;
  int value;
};

struct CmpLess {
  bool operator()(const Node& s, const Node& t) {
    return s.value < t.value;
  }
};

struct CmpGreater {
  bool operator()(const Node& s, const Node& t){
    return s.value > t.value;
  }
};

int main() {
  std::priority_queue<Node, std::vector<Node>, CmpLess> max_heap;
  std::priority_queue<Node, std::vector<Node>, CmpGreater> min_heap;

  max_heap.push({1, 1, 4});
  max_heap.push({1, 2, 1});
  max_heap.push({2, 1, 3});
  max_heap.push({1, 3, 5});
  max_heap.push({3, 3, 2});
  std::cout << "{ " << max_heap.top().from << ", "
     << max_heap.top().to << ", "
     << max_heap.top().value << " }\n";  // { 1, 3, 5 }

  min_heap.push({1, 1, 4});
  min_heap.push({1, 2, 1});
  min_heap.push({2, 1, 3});
  min_heap.push({1, 3, 5});
  min_heap.push({3, 3, 2});
  std::cout << "{ " << min_heap.top().from << ", "
     << min_heap.top().to << ", "
     << min_heap.top().value << " }\n";  // { 1, 2, 1 }

  return 0;
}

```

* [[BOJ] 가운데를 말해요](https://www.acmicpc.net/problem/1655) [(소스코드)](./src/exer5.cc) - 최소 힙과 최대 힙을 활용한 중앙값 출력 문제
  * 조건:
  1. `max_heap.size() >= min_heap.size()`
  2. `if max_heap.top() > min_heap.top() then swap`
  * 두 조건을 만족한다면, 중앙값은 `max_heap.top()`

  |input|execute|max_heap|min_heap|median|
  |:---:|-------|-------:|-------:|:----:|
  |1|insert to `max_heap`|`1`|`⠀`|1|
  |4|insert to `min_heap`|`1`|`4`|1|
  |6|insert to `max_heap`<br>swap|`6` `1`<br>`4` `1`|`4`<br>`6`|<br>4|

```c++
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
  int n;
  std::cin >> n;
  std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  while (n--) {
    int temp;
    std::cin >> temp;

    if (max_heap.size() <= min_heap.size())
      max_heap.push(temp);
    else
      min_heap.push(temp);

    if (!max_heap.empty() && !min_heap.empty() &&
        max_heap.top() > min_heap.top()) {
      max_heap.push(min_heap.top());
      min_heap.pop();
      min_heap.push(max_heap.top());
      max_heap.pop();
    }
    std::cout << max_heap.top() << '\n';
  }

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|