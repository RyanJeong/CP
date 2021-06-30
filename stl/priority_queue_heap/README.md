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

# [Priority Queue](https://cplusplus.com/reference/queue/priority_queue/)
* 힙(heap): 최대값 또는 최소값을 빠르게 찾아내기 위한 이진 트리이며, <b>이진 탐색 트리가 아님에 유의할 것</b>
* STL에서 제공하는 힙은 `priority_queue`이며, 최대힙을 나타냄
* 최소값 또는 최대값을 확인하는 것이 목적이라면, 균형 이진 트리를 통해서도 해를 구할 수 있지만 힙을 사용하는 것이 더 유리함
    * 균형 이진 트리를 사용하는 것보다 힙을 사용하는 것이 메모리를 적게 차지하고 동작 속도도 더 빠름

```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    priority_queue<int> pq;
    for (int i = 0; i<10; ++i) {
        pq.push(rand()%100);
    }
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
        /*
            93
            92
            86
            86
            83
            77
            49
            35
            21
            15
        */
    }

    return 0;
}
```
### 연습문제
* [[BOJ] 최대 힙](https://www.acmicpc.net/problem/11279)
###### Memory: 2,916 KB, Time: 16 ms
```c++
// https://www.acmicpc.net/problem/11279
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// https://en.cppreference.com/w/cpp/container/priority_queue 
	// priority_queue<int, vector<int>, greater<int>> -> min heap
	// priority_queue<int> -> max heap
	priority_queue<int> max_heap;

	while (n--) {
		int x;
		cin >> x;

		if (!x) {
			if (max_heap.empty()) {
				cout << "0\n";
			} 
			else {
				cout << max_heap.top() << '\n';
				max_heap.pop();
			}
		} 
		else {
			max_heap.push(x);
		}
	}

	return 0;
}
```

* [[BOJ] 최소 힙](https://www.acmicpc.net/problem/1927)
###### Memory: 2,916 KB, Time: 12 ms
```c++
// https://www.acmicpc.net/problem/1927
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// https://en.cppreference.com/w/cpp/container/priority_queue 
	// priority_queue<int, vector<int>, greater<int>> -> min heap
	// priority_queue<int> -> max heap
	priority_queue<int, vector<int>, greater<int>> min_heap;

	while (n--) {
		int x;
		cin >> x;

		if (!x) {
			if (min_heap.empty()) {
				cout << "0\n";
			} 
			else {
				cout << min_heap.top() << '\n';
				min_heap.pop();
			}
		} 
		else {
			min_heap.push(x);
		}
	}

	return 0;
}
```

* [[BOJ] 절댓값 힙](https://www.acmicpc.net/problem/11286)
	* 기본 자료형이 아닌 형에서의 최소 힙
###### Memory: 2,916 KB, Time: 16 ms
```c++
// https://www.acmicpc.net/problem/11286
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	priority_queue<pair<int, int>, 
		vector<pair<int, int>>, 
		greater<pair<int, int>>> min_heap;

	while (n--) {
		int x;
		cin >> x;

		if (!x) {
			if (min_heap.empty()) {
				cout << "0\n";
			} 
			else {
				cout << min_heap.top().second << '\n';
				min_heap.pop();
			}
		} 
		else {
			min_heap.push({abs(x),x});
		}
	}

	return 0;
}
```

* 직접 비교 연산자를 구현한 예
```c++
// 비교 대상은 node class에서의 value임
#include <bits/stdc++.h>

using namespace std;

struct node {
    int from;
    int to;
    int value;
};

struct cmp_less {
    bool operator()(node s, node t){

        return s.value<t.value;
    }
};

struct cmp_greater {
    bool operator()(node s, node t){

        return s.value>t.value;
    }
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<node, vector<node>, cmp_less> max_heap;
	priority_queue<node, vector<node>, cmp_greater> min_heap;

	max_heap.push({1,1,4});
	max_heap.push({1,2,1});
	max_heap.push({2,1,3});
	max_heap.push({1,3,5});
	max_heap.push({3,3,2});
	cout << "{ " << max_heap.top().from << ", "
	     << max_heap.top().to << ", "
		 << max_heap.top().value << " }\n"; // { 1, 3, 5 }

	min_heap.push({1,1,4});
	min_heap.push({1,2,1});
	min_heap.push({2,1,3});
	min_heap.push({1,3,5});
	min_heap.push({3,3,2});
	cout << "{ " << min_heap.top().from << ", "
	     << min_heap.top().to << ", "
		 << min_heap.top().value << " }\n"; // { 1, 2, 1 }

	return 0;
}
```


---
|[이전 - Array](/array/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - BFS & DFS](/bfs_dfs/)|
|-|-|-|