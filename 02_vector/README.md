* STL - Container Classes:
    * Sequence Container
        * [Vector](../02_vector/)
        * [List](../03_list/)
        * [Double-ended Queue(Deque)](../06_deque)
    * Container Adaptor
        * [Stack](../04_stack/)
        * [Queue](../05_queue/)
        * [Priority Queue](../21_priority_queue_heap)
    * Associative Container
        * [Set & Multiset](../19_set/)
        * [Map & Multimap](../20_map/)

# [WIP]Vector
* STL 컨테이너 중 하나
* 요소들을 순차적으로 보관하는 sequence container
* 벡터는 배열과 비슷하지만, 배열은 크기가 불변이지만 벡터는 크기가 가변임
* 벡터는 메모리 상에 요소들이 연속적으로 할당

## `push_back`
* 벡터의 마지막 요소 뒤에 새로운 요소를 추가하며, 시간복잡도는 `amortized O(1)`
    * 벡터의 저장 공간에 여유가 있을 때, 새로운 요소 추가 시 시간복잡도는 `O(1)`
    * https://modoocode.com/223
    * https://boycoding.tistory.com/236?category=1011971