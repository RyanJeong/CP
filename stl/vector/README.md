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
# Vector
* 추천 문제
  * [[BOJ] Strfry](https://www.acmicpc.net/problem/11328) [(소스코드)](./src/strfry.cc)
  * [[BOJ] 최대 GCD](https://www.acmicpc.net/problem/9417) [(소스코드)](./src/max_gcd.cc) - C++ 컨테이너 조작 방법을 연습하기에 좋은 문제
    * `cin.ignore`, `getline`
---

## [벡터(vector)](https://cplusplus.com/reference/vector/vector/)
* STL 컨테이너 중 하나
* 요소들을 순차적으로 보관하는 sequence container
* 벡터는 배열과 비슷하지만, 배열(static 배열에 한함)은 크기가 불변인 반면 벡터는 크기가 가변
* 벡터는 메모리 상에 요소들이 연속적으로 할당

## `(constructor)`, `operator=`
### [소스코드](./src/exam1.cc)
```c++
#include <iostream>
#include <vector>

int main() {
  // constructing std::vectors
  // constructors used in the same order as described above:

  // an empty vector
  std::vector<int> first;
  // a vector of size 4 with all values as 100
  std::vector<int> second(4, 100);
  // iterating through second
  std::vector<int> third(second.begin(), second.end());
  // use copy constructor
  std::vector<int> fourth(third);

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = { 16, 2, 77, 29 };
  std::vector<int> fifth(myints, myints + sizeof myints / sizeof(int));

  std::cout << "The contents of fifth are: ";
  // The contents of fifth are: 16 2 77 29
  // for (auto it = fifth.begin(); it != fifth.end(); ++it)
  //   std::cout << *it << ' ';
  for (const auto& i : fifth)
    std::cout << i << ' ';
  std::cout << '\n';

  // vector assignment
  std::vector<int> foo(3, 0);
  std::vector<int> bar = foo;
  foo = std::vector<int>();
  // foo's size: 0, foo's cap.: 0
  std::cout << "foo's size: " << foo.size()
       << ", foo's cap.: " << foo.capacity() << '\n';
  // bar's size: 3, bar's cap.: 3
  std::cout << "bar's size: " << bar.size()
       << ", bar's cap.: " << bar.capacity() << '\n';

  return 0;
}

```
---

## `push_back`
* 벡터의 마지막 요소 뒤에 새로운 요소를 추가하며, 시간복잡도는 <b>amortized O(1)</b>
  * 벡터의 저장 공간에 여유가 있을 때, 새로운 요소 추가 시 시간복잡도는 <b>O(1)</b>
  * 벡터의 요소 개수를 미리 알고 있다면, `reserve` 함수를 사용해 `push_back`의 시간복잡도를 <b>O(1)</b>로 만들 수 있음
* 벡터의 저장 공간이 꽉 찬 상태에서 `push_back` 연산을 수행하면, <i>capacity</i>가 현재 <i>capacity</i>의 두 배가 됨

## `pop_back`
* 벡터의 마지막 요소를 제거하며, <b><i>capacity</i>는 그대로 보존</b>

## `front`
* 벡터의 첫 번째 요소 값 반환
* <b>Calling this function on an empty container causes undefined behavior.</b>

## `back`
* 벡터의 마지막 요소 값 반환
* <b>Calling this function on an empty container causes undefined behavior.</b>

## `begin`
* 벡터의 시작 요소를 <i>iterator</i> 타입으로 반환

## `end`
* 벡터의 마지막 요소의 다음 요소 (범위 밖 요소)를 <i>iterator</i> 타입으로 반환

## `rbegin`
* 벡터의 마지막 요소를 <i>iterator</i> 타입으로 반환

## `rend`
* 벡터의 시작 요소의 이전 요소 (범위 밖 요소)를 <i>iterator</i> 타입으로 반환

## `insert`
* <i>iterator</i> 타입이 가리키는 위치에 값 삽입

## `erase`
* <i>iterator</i> 타입이 가리키는 위치에 존재하는 값 삭제
* 반환값은 <i>iterator</i>가 가리키고 있는 위치에서 <b>바로 뒤따르는 다음 요소 위치</b>를 <i>iterator</i> 타입으로 반환
* 벡터의 값이 저장되는 배열의 시작 위치는 항상 <b>고정</b>
  * `begin()` 값은 고정, `end()` 값이 바뀜 

## `swap`
* 두 벡터를 교환

## `clear`
* 벡터에 저장된 요소들을 비우되, <b><i>capacity</i>는 그대로 보존</b>

### [소스코드](./src/exam2.cc)
```c++
#include <iostream>
#include <vector>

int main() {
  // v1
  std::vector<int> v1(3, 5);
  std::cout << v1.size() << ' ' << v1.capacity() << '\n';  // 3 3
  for (const int& i : v1)
    std::cout << i << ' ';  // 5 5 5
  std::cout << '\n';

  v1.push_back(7);
  std::cout << v1.size() << ' ' << v1.capacity() << '\n';  // 4 6
  for (const int& i : v1)
    std::cout << i << ' ';  // 5 5 5 7
  std::cout << '\n';

  // v2
  std::vector<int> v2(2);
  std::cout << v2.size() << ' ' << v2.capacity() << '\n';  // 2 2
  for (const int& i : v2)
    std::cout << i << ' ';  // 0 0
  std::cout << '\n';

  v2.insert(v2.begin() + 1, 3);
  std::cout << v2.size() << ' ' << v2.capacity() << '\n';  // 3 4
  for (const int& i : v2)
    std::cout << i << ' ';  // 0 3 0
  std::cout << '\n';

  v2.pop_back();
  std::cout << v2.size() << ' ' << v2.capacity() << '\n';  // 2 4
  for (const int& i : v2)
    std::cout << i << ' ';  // 0 3
  std::cout << '\n';

  v2.swap(v1);  // swap between v1 and v2
  for (auto it = v2.begin(); it != v2.end(); ++it)
    std::cout << *it << ' ';  // 5 5 5 7
  std::cout << '\n';

  for (auto it = v2.rbegin(); it != v2.rend(); ++it)
    std::cout << *it << ' ';  // 7 5 5 5
  std::cout << '\n';

  std::cout << v2.size() << ' ' << v2.capacity() << '\n';  // 4 6
  v2.clear();
  std::cout << v2.size() << ' ' << v2.capacity() << '\n';  // 0 6
  for (const int& i : v2)
    std::cout << i << ' ';  // SKIP
  std::cout << '\n';

  // v3
  std::vector<int> v3;
  for (int i = 1; i < 10; ++i) {
    v3.push_back(i);
    std::cout << "size: " << v3.size() << ", cap.: " << v3.capacity() << '\n';
    /*
      size: 1, cap.: 1
      size: 2, cap.: 2
      size: 3, cap.: 4
      size: 4, cap.: 4
      size: 5, cap.: 8
      size: 6, cap.: 8
      size: 7, cap.: 8
      size: 8, cap.: 8
      size: 9, cap.: 16
    */
  }
  for (int i = 1; i < 10; ++i) {
    v3.pop_back();
    std::cout << "size: " << v3.size() << ", cap.: " << v3.capacity() << '\n';
    /*
      size: 8, cap.: 16
      size: 7, cap.: 16
      size: 6, cap.: 16
      size: 5, cap.: 16
      size: 4, cap.: 16
      size: 3, cap.: 16
      size: 2, cap.: 16
      size: 1, cap.: 16
      size: 0, cap.: 16
    */
  }

  // v4
  std::vector<int> v4 = { 1, 2, 4, 8, 16 };
  auto it_begin = v4.begin();
  auto it_end = v4.end();
  std::cout << v4.size() << ' ' << v4.capacity() << '\n';  // 5 5
  std::cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  std::cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  std::cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  std::cout << &(*v4.end()) << '\n';    // 0x7ffff727dec4

  // The base iterator refers to the element that is next to
  // the element the `reverse_iterator` is currently pointing to.
  // That is `std::reverse_iterator(it).base()` == `std::next(it)`.

  // v4.erase(v4.end() - 1);
  // Modern style: v4.erase(prev(v4.end()));
  v4.erase((v4.rbegin()).base() - 1);
  std::cout << v4.size() << ' ' << v4.capacity() << '\n';  // 4 5
  std::cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  std::cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  std::cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  std::cout << &(*v4.end()) << '\n';    // 0x7ffff727dec0
  for (const int& i : v4)
    std::cout << i << ' ';  // 1 2 4 8
  std::cout << '\n';

  v4.erase(v4.begin());
  std::cout << v4.size() << ' ' << v4.capacity() << '\n';  // 3 5
  std::cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  std::cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  std::cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  std::cout << &(*v4.end()) << '\n';    // 0x7ffff727debc
  for (const int& i : v4)
    std::cout << i << ' ';  // 2 4 8
  std::cout << '\n';

  v4.erase(v4.begin() + 1);
  std::cout << v4.size() << ' ' << v4.capacity() << '\n';  // 2 5
  std::cout << &(*it_begin) << '\n';    // 0x7ffff727deb0
  std::cout << &(*v4.begin()) << '\n';  // 0x7ffff727deb0
  std::cout << &(*it_end) << '\n';      // 0x7ffff727dec4
  std::cout << &(*v4.end()) << '\n';    // 0x7ffff727deb8
  for (const int& i : v4)
    std::cout << i << ' ';  // 2 8
  std::cout << '\n';

  *it_begin = 4;
  for (const int& i : v4)
    std::cout << i << ' ';  // 4 8
  std::cout << '\n';

  auto it = v4.erase(it_begin);
  *it_begin = 16;  // 8 will replace with 16
  for (const int& i : v4)
    std::cout << i << ' ';  // 16
  std::cout << '\n';

  return 0;
}

```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|