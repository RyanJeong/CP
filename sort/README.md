# [Sort](https://www.cplusplus.com/reference/algorithm/sort/)
## [Sort](https://en.cppreference.com/w/cpp/algorithm/sort), [Stable Sort](https://en.cppreference.com/w/cpp/algorithm/stable_sort) 
* <i>iterator</i> 타입 `first`와 `last` 사이에 있는 요소들을 정렬 
* `end`는 마지막 요소의 다음 요소를 가리킴에 주의
    * `[start, end)`
* `std:sort` is most likely to use [QuickSort](http://en.wikipedia.org/wiki/Quicksort), or at least a variation over QuickSort called [IntroSort](http://en.wikipedia.org/wiki/Introsort), which "degenerates" to [HeapSort](http://en.wikipedia.org/wiki/Heapsort) <b>when the recursion goes too deep</b>. From the standard:
    * The order of equal elements is not guaranteed to be preserved.
    * Complexity: <b><i>O</i>(<i>n log n</i>)</b> comparisons.

* `std::stable_sort` is most likely to use [MergeSort](http://en.wikipedia.org/wiki/Merge_sort), because of the stability requirement. However note that MergeSort <b>requires extra space in order to be efficient</b>. From the standard:
    * The order of equal elements is guaranteed to <b>be preserved</b>.
    * Complexity: It does at most <b>(<i>n log n</i>)<sup>2</sup></b> comparisons; if enough extra memory is available, it is <b><i>n log n</i></b>.
    * This function attempts to allocate a temporary buffer equal in size to the sequence to be sorted. If the allocation fails, the less efficient algorithm(<b>(<i>n log n</i>)<sup>2</sup></b>) is chosen.

## 정렬 알고리즘 종류 (Comparison Sort)
|[정렬 알고리즘](https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms)|시간복잡도:최선|시간복잡도:평균|시간복잡도:최악|필요메모리|
|-------------|----|----|----|-|
|Bubble Sort|<b><i>O</i>(<i>n</i>)</b>|<b><i>O</i>(<i>n</i><sup>2</sup>)</b>|<b><i>O</i>(<i>n</i><sup>2</sup>)</b>|<b><i>O</i>(1)</b>|
|Quick Sort|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n</i><sup>2</sup>)</b>|<b><i>O</i>(<i>log n</i>)</b>|
|Merge Sort|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n<i>)</b>|
|Heap Sort|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(<i>n log n</i>)</b>|<b><i>O</i>(1)</b>|
* Quicksort is usually done in-place with <b><i>O</i>(<i>log n</i>)</b> stack space.


### 정렬 알고리즘 성능 분석
* [[BOJ] 수 정렬하기](https://www.acmicpc.net/problem/2750) 
    * [Bubble Sort](./src/bubblesort.cpp) 
* [[BOJ] 수 정렬하기2](https://www.acmicpc.net/problem/2751) 
    * ~~[Bubble Sort](./src/bubblesort2.cpp)~~
        ###### <b>TLE</b>
    * ~~[Quick Sort](./src/quicksort.cpp)~~
        ###### <b>TLE</b>
    * [Merge Sort](./src/mergesort.cpp)
        ###### Memory: 9,832 KB, Time: 332 ms
    * [Heap Sort](./src/mergesort.cpp)
    * [std::sort](./src/std_sort.cpp)
        ###### Memory: 5,928 KB, Time: 288 ms
    * [std::stable_sort](./src/std_stable_sort.cpp)
        ###### Memory: 7,888 KB, Time: 296 ms


### `sort` 사용 예:
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	v.push_back(3);
	v.push_back(-2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(-1);

	// non-descending order
	sort(v.begin(),v.end()); // default comparison (operator <)
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	// descending order
	sort(v.begin(),v.end(),greater<int>()); // the standard library compare function object
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	// non-descending order
	sort(v.begin(),v.end(),less<int>()); // the standard library compare function object
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}
```

### 비교 함수를 직접 구현해 `sort` 사용:
```c++
#include <bits/stdc++.h>

using namespace std;

bool cmp_less(int, int);
bool cmp_greater(int, int);

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> v;
	v.push_back(3);
	v.push_back(-2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(-1);

	// non-descending order
	sort(v.begin(),v.end(),cmp_less); // default comparison (operator <)
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	// descending order
	sort(v.begin(),v.end(),cmp_greater); // the standard library compare function object
	for (int i : v) {
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}

bool cmp_less(int s, int t)
{

	return s<t;
}

bool cmp_greater(int s, int t)
{

	return s>t;
}
```

### 연습문제
* [[BOJ] Printer Queue](https://www.acmicpc.net/problem/1966) - `queue`와 `sort`를 이용하는 문제 
###### Memory: 2,024 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/1966
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	while (t--) {
		int n;
		cin>>n;
		int m;
		cin>>m;
		queue<pair<int, int>> q; // priority, index
		vector<int> v; // priority
		for (int i = 0; i<n; ++i) {
			int p;
			cin>>p;
			v.push_back(p);
			q.push({p,i});
		}
		sort(v.begin(),v.end(),greater<int>());
		int cnt = 0;
		for (int p : v) {
			while (p!=q.front().first) {
				auto cur = q.front();
				q.pop();
				q.push(cur);
			}	
			++cnt;
			if (m==q.front().second) {
				break;
			}
			q.pop();
		}
		cout << cnt << '\n';
	}

	return 0;
}
```

## 기타 정렬 (Non-comparison Sort)
###  Counting Sort (계수 정렬)
* [동작 애니메이션](http://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html)
* 시간복잡도는 <b><i>O</i>(<i>n</i>)</b>
* 비교를 하지 않으며, 빈도를 기록할 배열과 정렬 결과를 기록할 배열이 추가로 필요
* 정렬하는 대상이 특정 범위 내에 있을 경우 굉장히 효율적인 방법이지만, 범위가 특정하지 않거나 범위가 너무 넓을 경우 불필요한 메모리 낭비 발생
	* 정렬 대상이 8, 2, 1, 4, 64, 128일 경우, 빈도를 기록할 배열의 크기는 128
	* 정렬 대상 안에 10,000,000와 같이 큰 수가 포함되어 있다면, 배열의 크기는 최소 10,000,000 이상이여야 함
	
* [[BOJ] 수 정렬하기 5](https://www.acmicpc.net/problem/15688)
###### Memory: 9,828 KB, Time: 4,632 ms
```c++
// http://icpc.me/15688
#include <bits/stdc++.h>

using namespace std;

int arr[2'000'001]; // -1 000 000 ~ 1 000 000

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;
        ++arr[temp+1'000'000];
    }
    for (int i = 0; i<=2'000'000; ++i) {
        while (arr[i]--) {
            cout << i - 1'000'000 << '\n';
        }
    }

    return 0;
}
```

### Radix Sort



---
|[이전 - Greedy](/greedy/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Binary Search](/binary_search)|
|-|-|-|