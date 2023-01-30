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

# Set
* 추천 문제
  * [[BOJ] Easy work](https://www.acmicpc.net/problem/7785) [(소스코드)](./src/easy_work.cc) - 비교 함수를 사용한 예
---

## [셋(set)](https://cplusplus.com/reference/set/set/)
* [이진 검색 트리](/binary_search/)로 구현된 자료구조
* 컨테이너 안에는 하나의 값만 존재할 수 있으며, 컨테이너 안에 존재하는 값들은 <b>정렬되어 있음</b>
* `set`의 `insert`, `erase`, `find` 시간복잡도는 <b>O(<i>log n</i>)</b>

## [Multiple-key set](https://cplusplus.com/reference/set/multiset/)
* `multiset`은 `set`에서 값의 중복을 허용하는 자료구조

### [소스코드](./src/exam1.cc)
```c++
#include <iostream>
#include <set>

int main() {
  std::set<int> s;
  s.insert(3);          // { 3 }
  s.insert({5, 1, 7});  // { 1, 3, 5, 7 }
  if (s.find(6) == s.end())
    std::cout << "6 is not in 's'\n";  // 6 is not in 's'
  else
    std::cout << "6 is in 's'\n";
  std::cout << s.size() << '\n';  // 4

  s.erase(2);   // nop, { 1, 3, 5, 7 }
  s.erase(1);   // { 3, 5, 7 }
  s.insert(3);  // not allowed dup., { 3, 5, 7 }
  for (const auto& i : s)
    std::cout << i << ' ';  // 3 5 7
  std::cout << '\n';
  s.clear();

  std::multiset<int> ms;
  ms.insert(1);
  ms.insert(1);
  ms.insert(1);
  std::cout << ms.count(1) << '\n';  // { 1, 1, 1 }, => 3

  return 0;
}

```

## [Unordered Set](https://cplusplus.com/reference/unordered_set/unordered_set/)
* `unordered_set`은 해시 함수를 사용하며, `insert`, `erase`, `find`의 시간복잡도는 <b>O(1)</b>
* 컨테이너 안에는 하나의 값만 존재할 수 있으며, 컨테이너 안에 존재하는 값들은 <b>정렬되어 있지 않음</b>
  * 해시 충돌(hash collision)이 발생할 경우, 연결 리스트를 통해 값을 이어서 보관 ([chained hash](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining))
  * 해시 함수의 성능이 좋지 못해 해시 충돌이 빈번히 발생한다면, `find`의 시간복잡도는 최악의 경우 <b>O(<i>n</i>)</b> (이때 <i>n</i>의 개수는 동일한 해시 값을 갖는 요소들의 수)

## [Unordered Multiset](https://cplusplus.com/reference/unordered_set/unordered_multiset/)
* `unordered_multiset`은 `multiset`에서 값의 중복을 허용하는 자료구조

### [소스코드](./src/exam2.cc)
```c++
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
  std::unordered_set<std::string> us = {"red", "green", "blue"};
  std::string color = "red";
  auto it = us.find(color);

  if (it == us.end())
    std::cout << "not found.";
  else
    std::cout << *it << " is in the container.";  // red is in the container.
  std::cout << '\n';

  std::unordered_multiset<std::string> ums = {
      "red",
      "green",
      "red",
      "blue",
      "green"};
  if (ums.find("red") == ums.end())
    std::cout << "not found.";
  else
    std::cout << *ums.find("red") << " found.";  // red found.
  std::cout << '\n';

  return 0;
}

```

### 연습문제
* [[BOJ] Dual Priority Queue](https://www.acmicpc.net/problem/7662) [(소스코드)](./src/exer1.cc) - `set`을 이용한 양방향 Priority Queue 구현
```c++
#include <iostream>
#include <set>

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int k;
    std::cin >> k;
    std::multiset<int> ms;
    while (k--) {
      char c;
      std::cin >> c;
      int n;
      std::cin >> n;
      if (c == 'I') {
        ms.insert(n);
      } else if (n == 1) {  // c == 'D'
        if (!ms.empty())
          ms.erase(prev(ms.end()));
      } else {  // c == 'D' && n == -1
        if (!ms.empty())
          ms.erase(ms.begin());
      }
    }
    if (ms.empty())
      std::cout << "EMPTY\n";
    else
      std::cout << *(std::prev(ms.end())) << ' ' << *ms.begin() << '\n';
  }

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|