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

# Map
* 추천 문제
  * [[BOJ] LOZINKA](https://www.acmicpc.net/problem/9933) [(소스코드)](./src/lozinka.cc) - 기본 `map` 연산1
  * [[BOJ] 비밀번호 찾기](https://www.acmicpc.net/problem/17219) [(소스코드)](./src/pw.cpp) - 기본 `map` 연산2
  * [[BOJ] MALCOLM](https://www.acmicpc.net/problem/3078) [(소스코드)](./src/malcolm.cpp) - 중복 `map` 처리 문제
  * [[BOJ] Incognito](https://www.acmicpc.net/problem/9375) [(소스코드)](./src/incognito.cpp) - `map` 연산
---

## [맵(map)](https://cplusplus.com/reference/map/map/)
* [이진 검색 트리](/binary_search/)로 구현된 자료구조 (using highly balanced binary search trees, e.g. red-black tree, AVL tree)
* { <i>key</i>, <i>value</i> } 형태로 값 저장
* 컨테이너 안에는 하나의 <i>key</i>만 존재할 수 있음
* `map`의 `insert`, `erase`, `find` 시간복잡도는 <b>O(<i>log n</i>)</b>

## [Multiple-key map](https://cplusplus.com/reference/map/multimap/)
* `multimap`은 `map`에서 <i>key</i>의 중복을 허용하는 자료구조

### [소스코드](./src/exam1.cpp)
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
* `unordered_map`은 해시 함수를 사용하며, `insert`, `erase`, `find`의 시간복잡도는 <b>O(1)</b>
* 컨테이너 안에는 하나의 <i>key</i>만 존재할 수 있음
    * 해시 충돌(hash collision)이 발생할 경우, 연결 리스트를 통해 값을 이어서 보관 ([chained hash](https://en.wikipedia.org/wiki/Hash_table#Separate_chaining))
    * 해시 함수의 성능이 좋지 못해 해시 충돌이 빈번히 발생한다면, `find`의 시간복잡도는 최악의 경우 <b>O(<i>n</i>)</b> (이때 <i>n</i>의 개수는 동일한 해시 값을 갖는 요소들의 수)
## [Unordered Multimap](https://cplusplus.com/reference/unordered_map/unordered_multimap/)
* `unordered_multimap`은 `multimap`에서 <i>key</i>의 중복을 허용하는 자료구조

### [소스코드](./src/exam2.cpp)
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

### 연습문제
* [[BOJ] 나는야 포켓몬 마스터 이다솜](https://www.acmicpc.net/problem/1620) [(소스코드)](./src/exer1.cpp) - `c_str` 함수와 두 개의 `map` 사용 예
```c++
// https://www.acmicpc.net/problem/1620
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int m;
    cin>>m;
    map<string, int> m_stoi;
    map<int, string> m_itos;
    for (int i = 1; i<=n; ++i) {
        string str;
        cin>>str;
        m_stoi[str]=i;
        m_itos[i]=str;
    }
    for (int i = 1; i<=m; ++i) {
        string str;
        cin>>str;
        if (isdigit(str.front())) {
            cout << m_itos[atoi(str.c_str())] << '\n';
        }
        else {
            cout << m_stoi[str] << '\n';
        }
    }

    return 0;
}
```

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|