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

# [Set](https://cplusplus.com/reference/set/set/)
* [이진 검색 트리](/binary_search/)로 구현된 자료구조
* 컨테이너 안에는 하나의 값만 존재할 수 있음
* `set`의 `insert`, `erase`, `find` 시간복잡도는 <b><i>O</i>(<i>log n</i>)</b>
## [Multiple-key set](https://cplusplus.com/reference/set/multiset/)
* `multiset`은 `set`에서 값의 중복을 허용하는 자료구조

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    set<int> s;
    s.insert(3); // { 3 }
    s.insert({ 5, 1, 7 }); // { 1, 3, 5, 7 }
    if (s.find(6)==s.end()) {
        cout << "6 is not in 's'\n"; // 6 is not in 's'
    } 
    else {
        cout << "6 is in 's'\n";
    }
    cout << s.size() << '\n'; // 4

    s.erase(2);  // nop, { 1, 3, 5, 7 }
    s.erase(1);  // { 3, 5, 7 }
    s.insert(3); // not allowed dup., { 3, 5, 7 }
    for (auto i : s) {
        cout << i << ' '; // 3 5 7
    }
    cout << '\n';
    s.clear();

    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    cout << ms.count(1) << '\n'; // { 1, 1, 1 }, => 3

    return 0;
}
```

## [Unordered Set](https://cplusplus.com/reference/unordered_set/unordered_set/)
* `unordered_set`은 해시 함수를 사용하며, `insert`, `erase`, `find`의 시간복잡도는 <b><i>O</i>(1)</b>
* 컨테이너 안에는 하나의 값만 존재할 수 있음
    * 해시 충돌(hash collision)이 발생할 경우, 연결 리스트를 통해 값을 이어서 보관 ([chained hash](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining))
    * 해시 함수의 성능이 좋지 못해 해시 충돌이 빈번히 발생한다면, `find`의 시간복잡도는 최악의 경우 <b><i>O</i>(<i>n</i>)</b> (이때 <i>n</i>의 개수는 동일한 해시 값을 갖는 요소들의 수)

## [Unordered Multiset](https://cplusplus.com/reference/unordered_set/unordered_multiset/)
* `unordered_multiset`은 `multiset`에서 값의 중복을 허용하는 자료구조

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    unordered_set<string> us = {"red","green","blue"};
    string color="red";
    auto it = us.find(color);

    if (it==us.end()) {
        cout << "not found.";
    }
    else {
        cout << *it << " is in the container."; // red is in the container.
    }
    cout << '\n';

    unordered_multiset<string> ums = {"red","green","red","blue","green"};
    if (ums.find("red")==ums.end()) {
        cout << "not found.";
    }
    else {
        cout << *ums.find("red") << " found."; // red found.
    }
    cout << '\n';

    return 0;
}
```


---
|[이전 - Array](../Array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](../bfs_dfs/)|
|-|-|-|
