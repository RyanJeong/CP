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

# [Map](https://cplusplus.com/reference/map/map/)
* [이진 검색 트리](/binary_search/)로 구현된 자료구조 (using highly balanced binary search trees, e.g. red-black tree, AVL tree)
* { <i>key</i>, <i>value</i> } 형태로 값 저장
* 컨테이너 안에는 하나의 <i>key</i>만 존재할 수 있음
* `map`의 `insert`, `erase`, `find` 시간복잡도는 <b><i>O</i>(<i>log n</i>)</b>
## [Multiple-key map](https://cplusplus.com/reference/map/multimap/)
* `multimap`은 `map`에서 <i>key</i>의 중복을 허용하는 자료구조

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    map<string, int> m; // key: string, value: int
    m["Jeong"]=123456; // { { "Jeong", 123456 } }
    m["Oh"]=234567; // { { "Jeong", 123456 }, { "Oh", 234567 } }
    m["Park"]=345678; // { { "Jeong", 123456 }, { "Oh", 234567 }, { "Park", 345678 } }
    for (auto e: m) {
        cout << e.first << ' ' << e.second << '\n';
        /*
            Jeong 123456
            Oh 234567
            Park 345678
        */
    }

    m["Park"]=876543; // { { "Jeong", 123456 }, { "Oh", 234567 }, { "Park", 876543 } }
    cout << m["Park"] << '\n'; // 876543

    m.erase("QWERT"); // nop
    m.erase("Park"); // { { "Jeong", 123456 }, { "Oh", 234567 } }
    for (auto e: m) {
        cout << e.first << ' ' << e.second << '\n';
        /*
            Jeong 123456
            Oh 234567
        */
    }
    m.clear();

    multimap<int, string> ms;
    ms.insert({1, "Hi" });  // { { 1, "Hi" } }
    ms.insert({1, "Hello" }); // { { 1, "Hi" }, { 1, "Hello" } }
    ms.insert({2, "Bye" }); // { { 1, "Hi" }, { 1, "Hello" }, { 2, "Bye" } }

    for (auto e: ms) {
        cout << e.first << " " << e.second << '\n';
        /*
            1 Hi
            1 Hello
            2 Bye
        */
    }

    return 0;
}
```

## [Unordered Map](https://cplusplus.com/reference/unordered_map/unordered_map/)
* `unordered_map`은 해시 함수를 사용하며, `insert`, `erase`, `find`의 시간복잡도는 <b><i>O</i>(1)</b>
* 컨테이너 안에는 하나의 <i>key</i>만 존재할 수 있음
    * 해시 충돌(hash collision)이 발생할 경우, 연결 리스트를 통해 값을 이어서 보관 ([chained hash](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining))
    * 해시 함수의 성능이 좋지 못해 해시 충돌이 빈번히 발생한다면, `find`의 시간복잡도는 최악의 경우 <b><i>O</i>(<i>n</i>)</b> (이때 <i>n</i>의 개수는 동일한 해시 값을 갖는 요소들의 수)
## [Unordered Multimap](https://cplusplus.com/reference/unordered_map/unordered_multimap/)
* `unordered_multimap`은 `multimap`에서 <i>key</i>의 중복을 허용하는 자료구조

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    unordered_map<string, double> umap = {
        {"Jeong", 6.1},
        {"Park", 10.4},
        {"Kim", 11.2} 
    };
    string str = "Jeong";
    auto it = umap.find(str);
    if (it==umap.end()) {
        cout << "Not found.";
    }
    else {
        cout << it->first << " is " << it->second; // Jeong is 6.1
    }
    cout << '\n';

    unordered_multimap<string, string> ummap = {
        {"Jeong","C"},
        {"Jeong","C++"},
        {"Kim","Java"},
        {"Oh","Kotlin"}
    };
    cout << ummap.find("Jeong")->second;

    return 0;
}
```

---
|[이전 - Array](../Array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](../bfs_dfs/)|
|-|-|-|