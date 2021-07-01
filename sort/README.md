# [Sort](https://www.cplusplus.com/reference/algorithm/sort/)
## `sort`
###### default (1)
```c++
template <class RandomAccessIterator>
  void sort(RandomAccessIterator first, RandomAccessIterator last);
```
###### default (2)
```c++
template <class RandomAccessIterator, class Compare>
  void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```
* `sort` 함수는 <i>iterator</i> 타입 `first`와 `last` 사이에 있는 요소들을 정렬
* `[start, end)`
* Quick sort를 기반으로 구현되어 있으며, `sort`의 시간복잡도는 <b><i>O</i>(<i>n log n</i>)</b>
* 추천 문제
	* [[BOJ] 수 정렬하기](https://www.acmicpc.net/problem/2750) [(소스코드 - Bubble Sort)](./src/bubblesort.cpp) [(소스코드 - Merge Sort)](./src/mergesort.cpp)
	* [[BOJ] 수 정렬하기2](https://www.acmicpc.net/problem/2751) [(소스코드)](./src/stl_sort.cpp)

### `sort` 예제
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

### 비교 함수 사용 예
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

---
|[이전 - Greedy](/greedy/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Binary Search](/binary_search)|
|-|-|-|