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

# [List](https://cplusplus.com/reference/list/list/)
* 연결 리스트(linked list)
* 요소들은 메모리 상에 불연속적으로 위치할 수 있음

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // In C++, an iterator is any object that, pointing to some element in a range of elements 
    // (such as an array or a container), has the ability to iterate through the elements 
    // of that range using a set of operators (at least, the increment (++) and dereference 
    // (*) operators).
    list<int> l = {1,2}; // 1 -> 2
    list<int>::iterator p = l.begin(); // p points to '1'

    l.push_front(10);   // { 10, 1, 2 } 
    cout << *p << '\n'; // 1

    l.push_back(5); // { 10, 1, 2, 5 }; 
    l.insert(p,6);  // { 10, 6, 1, 2, 5 }, insert where p is pointing
                    // p still points to '1'
    ++p; // now p points from '1' to '2'
         // function erase() returns an iterator pointing to the element in the list
         // container which followed the 'last' element erased from the list container 
         // erased from the list container.

    p = l.erase(p); // erase where p is pointing (2 will removed)
                    // now p points to '5'
    cout << *p << '\n';  // 5
    p = l.end(); // now p points to the element after '5' that we don't know what the value is.
    cout << *p << '\n';  // ?? 
    for (int i : l) {
        cout << i << ' '; // 10 6 1 5
    }
    cout << '\n';

    // usage function begin() and end()
    for (auto ptr = l.begin(); ptr!=l.end(); ++ptr) {
        cout << *ptr << ' '; // 10 6 1 5
    } 
    cout << '\n';

    return 0;
}
```


---
|[이전 - Array](../Array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](../bfs_dfs/)|
|-|-|-|