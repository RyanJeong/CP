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
        * [Set & Multiset](/stl/set/)
        * [Map & Multimap](/stl/map/)

# STL - Container Classes:
## Sequence Container
### [Vector](/stl/vector/)
* A vector is a fixed length group of elements of uniform type, indexed by integer keys. Vectors can be considered to be a generalization of the built-in C++ array type.
* Vectors are useful when:
    * the number of items to be maintained by a collection is at least approximately known in advance.
    * As with arrays, vector elements can be directly indexed.
    * The sorting operation can be used to place the elements of a vector in order.
    * Accessing an element of a vector, read/write, can be performed in constant that is <b>O(1)</b> time.
    * Searching an unordered vector can be accomplished in <b>O(<i>n</i>)</b> time.
    * Searching a sorted vector can be accomplished in <b>O(<i>logn</i>)</b> time using binary search.
    * A notable operation on vectors, not possible with arrays, is that the size of the vector can dynamically be increased or decrease. Such operation may take <b>O(<i>n</i>)</b> worst case scenario.

		|Operation|Capacity|Cost||
		|:-:|:-:|-:|-|
		|`push_back(1)`|1|1|`1`|
		|`push_back(2)`|2|<b>1</b>+1|`1` `2`|
		|`push_back(3)`|4|<b>2</b>+1|`1` `2` `3` `⠀`|
		|`push_back(4)`|4|1|`1` `2` `3` `4` |
		|`push_back(5)`|8|<b>4</b>+1|`1` `2` `3` `4` `5` `⠀` `⠀` `⠀`|
		|`push_back(6)`|8|1|`1` `2` `3` `4` `5` `6` `⠀` `⠀`|
		|`push_back(7)`|8|1|`1` `2` `3` `4` `5` `6` `7` `⠀`|
		|`push_back(8)`|8|1|`1` `2` `3` `4` `5` `6` `7` `8`|
		|`push_back(9)`|16|<b>8</b>+1|`1` `2` `3` `4` `5` `6` `7` `8` `9` `⠀` `⠀` `⠀` `⠀` `⠀` `⠀` `⠀`|
		* <b>amortized O(<i>n</i>)</b>
        * Assume that you call `push_back(x)` <i>N</i> times.
        * The total cost comprises of:
            * Cost of adding an element
                * 1 operation per `push_back(x)`
                * Total <i>N</i> operations for <b><i>N</i></b> `push_back(x)`
            * Cost of moving elements when vector is <b>full</b>
                * 1, 2, 4, 8, ..., 2<sup><i>k</i></sup> (where 2<sup><i>k</i></sup> < <i>N</i>)
                * The sum of above = <b>2<sup><i>k</i>+1</sup>-1 < 2<i>N</i></b>
        * Total cost for <i>N</i> `push_back(x)` = <i>N</i> + (<2<i>N</i>) < 3<i>N</i>, and therefore is <b>O(<i>N</i>)</b>.
        * We can say that `push_back(x)` is <b>amortized O(1)</b>


### [List](/stl/list/)
* A list is a data structure of choice when the number of elements in a collection <b>cannot be bounded</b>, or varies widely during the course of execution. 
* Like a vector, a list maintains values of uniform type. Lists are not indexed, instead elements must be examined one by one in sequence.
### [Double-ended Queue(Deque)](/stl/deque/)
* A deque or double ended queue is a data structure of an arbitrary size, growing and shrinking as elements are added or removed. The deque is optimized for insertion or removal of elements from either end. This operation can be performed in constant time.
* Like a vector dequeue is an indexed structure, allowing rapid access to any element. As values are inserted into the front of the structure, the index positions by which an element is accessed will constantly change to reflect the inclusion of the new values. Deques can be ordered and use binary search to locate a specific element, otherwise linear search is necessary.
---

## Container Adaptor
### [Stack](/stl/stack/)
*
### [Queue](/stl/queue/)
*
### [Priority Queue](/stl/priority_queue_heap)
*
---

## Associative Container
### [Set & Multiset](/stl/set/)
*
### [Map & Multimap](/stl/map/)
*

---
|[이전 - Array](../Array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](../bfs_dfs/)|
|-|-|-|