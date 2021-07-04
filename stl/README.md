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

# STL - Container Classes:
* Calling a function that accesses a element of a container while <b>the container is empty</b> is <b>UB(<i>undefined behavior</i>)</b>.

## Sequence Container
### [Vector](/stl/vector/)
* A vector is a fixed length group of elements of uniform type, indexed by integer keys. Vectors can be considered to be a generalization of the built-in C++ array type.
* Vectors are useful when:
    * the number of items to be maintained by a collection is at least approximately known in advance.
    * As with arrays, vector elements can be directly indexed.
    * The sorting operation can be used to place the elements of a vector in order.
    * Accessing an element of a vector, read/write, can be performed in constant that is <b>O(1)</b> time.
    * Searching an unordered vector can be accomplished in <b>O(<i>n</i>)</b> time.
    * Searching a sorted vector can be accomplished in <b>O(<i>log n</i>)</b> time using binary search.
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
        * [<b>amortized O(<i>n</i>)</b>](https://cs.stackexchange.com/questions/9380/why-is-push-back-in-c-vectors-constant-amortized)
        > Amortized analysis is an analysis technique that examines a sequence of <i>n</i> operations. If the whole sequence runs in <b><i>T</i>(<i>n</i>)</b> time, then each operation in the sequence runs in <b><i>T</i>(<i>n</i>)/<i>n</i></b>. The idea is that while a few operations in the sequence might be costly, they can't happen often enough to weigh down the program. It's important to note that this is different from average case analysis over some input distribution or randomized analysis. Amortized analysis established a <i>worst case</i> bound for the performance of an algorithm irrespective of the inputs. It's most commonly used to analyse data structures, which have a persistent state throughout the program.

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
* <b>Like a vector, a list maintains values of uniform type</b>. Lists are <b>not indexed</b>, instead elements must be examined one by one in sequence.
### [Double-ended Queue(Deque)](/stl/deque/)
* A deque or double ended queue is a data structure of an arbitrary size, growing and shrinking as elements are added or removed. <b>The deque is optimized for insertion or removal of elements from either end</b>. This operation can be performed in constant time.
* Like a vector dequeue is an <b>indexed</b> structure, allowing rapid access to any element. As values are inserted into the front of the structure, the index positions by which an element is accessed will constantly change to reflect the inclusion of the new values. <b>Deques can be ordered and use binary search</b> to locate a specific element, otherwise linear search is necessary.
---

## Container Adaptor
### [Stack](/stl/stack/)
* Elements in a stack obey the <b>last-in first-out</b>, or <b>LIFO</b> protocol, in that elements can be added or removed only from the front of the stack.

### [Queue](/stl/queue/)
* A queue maintains a <b>first-in, first-out</b> protocol or <b>FIFO</b>. Elements are inserted in the back of the queue and removed from the front. <b>The element removed from the queue is the one that was held the longest</b>.
### [Priority Queue](/stl/priority_queue_heap)
* <b>A priority queue is optimized for insertion of arbitrary new elements and for removal of the largest element</b>, both operations can be performed in <b>O(<i>log n</i>)</b> time.
---

## Associative Container
### [Set](/stl/set/)
* <b>A set is a simple collection of unique values</b>. The set data structure <b>maintains values in an ordered representation</b>. This permits rapid insertion, removal and testing for inclusion of a specific element. All operations can be performed in <b>O(<i>log n</i>)</b> time. In addition, <b>operations are provided for forming the intersection and union of two sets</b>.

### [Map](/stl/map/)
* A map (sometimes called a <b>dictionary</b> or a <b>table</b>) is, like a vector, an <b>indexed</b> collection. However, unlike a vector, the <b>index values need not be integer</b>, but can be any ordered data values. A map can therefore be thought of as a collection of associations of keys and value pairs.
---

## Selecting a container:
### How are values going to be accessed?
* If <b>random access</b> is important, then `vector` or `deque` should be used.
* If values are going to <b>be accessed in order</b> then `set` should be used. 
* If <b>sequential access</b> is sufficient then any other structure is suitable.

### Is the order in which values are maintained important?
* If <b>strict ordering is important</b>, then `set` is the best choice.
* If the order that values are <b>held in the structure is related to the order of insertion</b>, then `stack`, `queue` or `list` may be the best choice.

### Will the size of the structure vary widely over the course of execution?
* If true, then `list` or `set` may be suitable, as they only use memory to <b>hold currently stored values</b>, while a `vector` or `deque` will continue to maintain a large buffer <b>even after elements have been removed</b>.

### Is it possible to estimate the size of the collection of values?
* `vector` provides a way to pre-allocate a block of memory of a given size (`reserve()`).

### Is testing whether a value is contained in the collection a frequent operation?
* If so, then the `set` or `map` would be a good choice. Testing to see whether a value is contained in `set` or `map` can be performed in a very small number of steps.

### Is the collection indexed: Can it be viewed as a series of key/value pairs?
* If the keys are between 0 and some upper limit, then `vector` or `deque` should be employed. If on the other hand, the key values are some other ordered data type, then `map` can be used.

### Can values be related to each other?
* If values cannot be ordered using `≤` operator, then we should use `set` or `map`.

### Is finding and removing the largest value from the collection a frequent operation?
* `priority_queue`

### At what positions are values inserted into or removed from the structure?
* Insertion/removal from the middle: `list`
* Insertion from beginning: `list` or `deque`
* Insertion/deletion from the end: `stack` or `queue`

### Is the merging of two or more sequences into one a frequent operation?
* `set` or `list` are best choice.

---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|