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

# List
* 추천 문제
  * [[BOJ] editor](https://www.acmicpc.net/problem/1406) [(소스코드)](./src/editor.cc)
  * [[BOJ] Keylogger](https://www.acmicpc.net/problem/5397) [(소스코드)](./src/keylogger.cc)

## [리스트(list)](https://cplusplus.com/reference/list/list/)
* 연결 리스트(linked list)
* 요소들은 메모리 상에 불연속적으로 위치할 수 있음

### [소스코드](./src/exam.cc)
```c++
#include <iostream>
#include <list>

int main() {
  // In C++, an iterator is any object that, pointing to some element in a
  // range of elements(such as an array or a container), has the ability to
  // iterate through the elements of that range using a set of operators
  // (at least, the increment (++) and dereference (*) operators).
  std::list<int> l = { 1, 2 };  // 1 -> 2
  std::list<int>::iterator p = l.begin();  // p points to '1'

  l.push_front(10);    // { 10, 1, 2 }
  std::cout << *p << '\n';  // 1

  l.push_back(5);  // { 10, 1, 2, 5 };
  l.insert(p, 6);  // { 10, 6, 1, 2, 5 }, insert where p is pointing
                   // p still points to '1'
  ++p;  // now p points from '1' to '2'

  // function erase() returns an iterator pointing to the element in the list
  // container which followed the last element erased from the list container.
  p = l.erase(p);  // erase where p is pointing (2 will removed)
                   // now p points to '5'
  std::cout << *p << '\n';  // 5
  p = l.end();  // now p points to the element after '5' that we don't know
                // what the value is.
  std::cout << *p << '\n';  // ??

  // range-based for loop
  for (const int& i : l)
    std::cout << i << ' ';  // 10 6 1 5
  std::cout << '\n';
  // usage function begin() and end()
  for (auto ptr = l.begin(); ptr != l.end(); ++ptr)
    std::cout << *ptr << ' ';  // 10 6 1 5
  std::cout << '\n';

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|