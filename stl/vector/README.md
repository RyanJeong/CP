* [STL - Container Classes:](./stl/)
    * Sequence Container
        * [Vector](./stl/vector/)
        * [List](./stl/list/)
        * [Double-ended Queue(Deque)](./stl/deque/)
    * Container Adaptor
        * [Stack](./stl/stack/)
        * [Queue](./stl/queue/)
        * [Priority Queue](./stl/priority_queue_heap/)
    * Associative Container
        * [Set & Multiset](./stl/set/)
        * [Map & Multimap](./stl/map/)

# [WIP]Vector
* STL 컨테이너 중 하나
* 요소들을 순차적으로 보관하는 sequence container
* 벡터는 배열과 비슷하지만, 배열은 크기가 불변이지만 벡터는 크기가 가변임
* 벡터는 메모리 상에 요소들이 연속적으로 할당

## `push_back`
* 벡터의 마지막 요소 뒤에 새로운 요소를 추가하며, 시간복잡도는 `amortized O(1)`
    * 벡터의 저장 공간에 여유가 있을 때, 새로운 요소 추가 시 시간복잡도는 `O(1)`
    * https:/modoocode.com/223
    * https:/boycoding.tistory.com/236?category=1011971
    * https://thuthi.tistory.com/entry/vector-pushback%EC%9D%80-%EB%8A%90%EB%A6%AC%EB%8B%A4-reserve