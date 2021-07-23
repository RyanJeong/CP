# [Sort](https://www.cplusplus.com/reference/algorithm/sort/)
## [Sort](https://en.cppreference.com/w/cpp/algorithm/sort), [Stable Sort](https://en.cppreference.com/w/cpp/algorithm/stable_sort) 
* 추천 문제
    * [[BOJ] 단어 정렬](https://www.acmicpc.net/problem/1181) [(소스코드)](./src/sort_word.cpp) - `sort` 함수를 사용하며, 비교 함수를 직접 구현하는 예
    * [[BOJ] 나이순 정렬](https://www.acmicpc.net/problem/10814) [(소스코드)](./src/sort_age.cpp) - `stable_sort` 함수를 사용하며, 비교 함수를 직접 구현하는 예
    * [[BOJ] Multi-key Sorting](https://www.acmicpc.net/problem/3340) [(소스코드)](./src/stable_sort_feat.cpp) - `stable_sort` 의 특징을 알 수 있는 문제
    * [[Programmers] 전화번호 목록](https://programmers.co.kr/learn/courses/30/lessons/42577) [(소스코드)](./src/phone_book.cpp) - 문자열을 대상으로 정렬했을 때의 결과를 생각하면 답이 보이는 문제
    * [[BOJ] K번째 수 찾는 함수](https://www.acmicpc.net/problem/16455) [(소스코드)](./src/nth_element.cpp) - `nth_element` 함수 사용 문제
* <i>iterator</i> 타입 `first`와 `last` 사이에 있는 요소들을 정렬 
* `end`는 마지막 요소의 다음 요소를 가리킴에 주의
    * `[start, end)`
* `std:sort` is most likely to use [QuickSort](http://en.wikipedia.org/wiki/Quicksort), or at least a variation over QuickSort called [IntroSort](http://en.wikipedia.org/wiki/Introsort), which "degenerates" to [HeapSort](http://en.wikipedia.org/wiki/Heapsort) <b>when the recursion goes too deep</b>. From the standard:
    * The order of equal elements is not guaranteed to be preserved.
    * Complexity: <b>O(<i>n log n</i>)</b> comparisons.

* `std::stable_sort` is most likely to use [MergeSort](http://en.wikipedia.org/wiki/Merge_sort), because of the stability requirement. However note that MergeSort <b>requires extra space in order to be efficient</b>. From the standard:
    * The order of equal elements is guaranteed to <b>be preserved</b>.
    * Complexity: It does at most <b>(<i>n log n</i>)<sup>2</sup></b> comparisons; if enough extra memory is available, it is <b><i>n log n</i></b>.
    * This function attempts to allocate a temporary buffer equal in size to the sequence to be sorted. If the allocation fails, the less efficient algorithm(<b>(<i>n log n</i>)<sup>2</sup></b>) is chosen.

## [정렬 알고리즘 종류 (Comparison Sort)](https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms)
|정렬 알고리즘|시간복잡도:최선|시간복잡도:평균|시간복잡도:최악|필요메모리|
|-------------|----|----|----|-|
|Bubble Sort|<b>O(<i>n</i>)</b>|<b>O(<i>n</i><sup>2</sup>)</b>|<b>O(<i>n</i><sup>2</sup>)</b>|<b>O(1)</b>|
|Quick Sort|<b>O(<i>n log n</i>)</b>|<b>O(<i>n log n</i>)</b>|<b>O(<i>n</i><sup>2</sup>)</b>|<b>O(<i>log n</i>)</b>|
|Merge Sort|<b>O(<i>n log n</i>)</b>|<b>O(<i>n log n</i>)</b>|<b>O(<i>n log n</i>)</b>|<b>O(<i>n<i>)</b>|
|Heap Sort|<b>O(<i>n log n</i>)</b>|<b>O(<i>n log n</i>)</b>|<b>O(<i>n log n</i>)</b>|<b>O(1)</b>|
* Quicksort is usually done in-place with <b>O(<i>log n</i>)</b> stack space.


### 정렬 알고리즘 성능 분석
* [[BOJ] 수 정렬하기2](https://www.acmicpc.net/problem/2751) 
    * ~~Bubble Sort~~ [(소스코드)](./src/bubblesort2.cpp)
        ###### <b>TLE</b>
    * ~~Quick Sort~~ [(소스코드)](./src/quicksort.cpp)
        ###### <b>TLE</b>
    * Merge Sort [(소스코드)](./src/mergesort.cpp)
        ###### Memory: 9,832 KB, Time: 332 ms
    * Heap Sort [(소스코드)](./src/mergesort.cpp)
        ###### Memory: 10,148 KB, Time: 360 ms
    * std::sort [(소스코드)](./src/std_sort.cpp)
        ###### Memory: 5,928 KB, Time: 288 ms
    * std::stable_sort [(소스코드)](./src/std_stable_sort.cpp)
        ###### Memory: 7,888 KB, Time: 296 ms


### [소스코드](./src/exam1.cpp) - `sort` 사용 예:
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

### [소스코드](./src/exam2.cpp) - 비교 함수를 직접 구현해 `sort` 사용:
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
* [[BOJ] Printer Queue](https://www.acmicpc.net/problem/1966) [(소스코드)](./src/exer1.cpp) - `queue`와 `sort`를 이용하는 문제 
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
* 대상 간 비교를 직접 하지 않음
* 비교해야 할 대상 수가 <i>n</i>이고, 대상의 범위가 <i>k</i>일 때, 시간복잡도는 <b>O(<i>n</i>+<i>k</i>)</b>이고 공간복잡도는 <b>O(<i>n</i>+<i>k</i>)</b>
* 정렬하는 대상이 특정 범위 내에 있을 경우 굉장히 효율적인 방법이지만, 범위가 특정하지 않거나 범위가 너무 넓을 경우 불필요한 메모리 낭비가 발생함
    * 정렬 대상이 8, 2, 1, 4, 64, 128일 경우, 빈도를 기록할 배열의 크기는 128
    * 정렬 대상 안에 10,000,000와 같이 큰 수가 포함되어 있다면, 배열의 크기는 최소 10,000,000 이상이여야 함

### [소스코드](./src/exam3.cpp)
```c++
// C++ implementation of Counting Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // k : 1 ~ 200
    int arr[] = {174,84,75,22,123,24,2,78};
    int freq[1+200]; // 0, 1 ~ k
    memset(freq,0,sizeof freq);

    // n times
    for (int i : arr) {
        ++freq[i];
    }
    // k times + n times
    // when for-statement completes k iterations, 
    // while-loop executes a total of n operations
    // => 2n + k, O(n + k)
    for (int i = 1; i<=200; ++i) {
        // 
        while (freq[i]--) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}
```
    
### 연습문제
* [[BOJ] 수 정렬하기 3](https://www.acmicpc.net/problem/10989) [(소스코드)](./src/exer2.cpp) - 공간복잡도를 <b>O(<i>k</i>)</b>로 절약한 예
###### Memory: 2,060 KB, Time: 1,600 ms
```c++
// https://www.acmicpc.net/problem/10989
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    static int freq[10'001];
    int low = 10'000;
    int high = 1;
    int n;
    cin>>n;
    // n times
    for (int i = 0; i<n; ++i) {
        int temp;
        cin>>temp;
        ++freq[temp];
        low=min(low,temp);
        high=max(high,temp);
    }
    // k times + n times
    for (int i = low; i<=high; ++i) {
        while (freq[i]--) {
            cout << i << '\n';
        }
    }

    return 0;
}
```

### Radix Sort (기수 정렬)
* 대상 간 비교를 직접 하지 않음
* 비교해야 할 대상 수가 <i>n</i>이고, 기수(radix)의 수가 <i>l</i>, 대상의 범위가 <i>k</i>일 때, 시간복잡도는 <b>O(<i>l</i>×(<i>n</i>+<i>k</i>))</b>이고 공간복잡도는 <b>O(<i>n</i>+<i>k</i>)</b>
* 기수 크기만큼의 메모리가 추가로 필요함  

### [소스코드](./src/exam4.cpp)
```c++
// C++ implementation of Radix Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {174,84,75,22,723,24,2,78};
    int n = sizeof arr/sizeof(int);
    int max_n = 0;
    for (int i : arr) {
        max_n=max(max_n,i);    
    }

    // Radix Sort
    // the digit represented by d
    // l times
    for (int d = 1; max_n/d>0; d*=10) {
        vector<int> v[10];
        // n times
        for (int i = 0; i<n; ++i) {
            int idx = (arr[i]/d)%10;
            v[idx].push_back(arr[i]);
        }
        // k times
        int i = 0;
        for (int j = 0; j<10; ++j) {
            for (auto elem : v[j]) {
                arr[i++]=elem;
            }
        }
    }
    for (int i : arr) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
```

### 연습문제
* 1 byte를 기수로 사용해 정렬 [(소스코드)](./src/exer3.cpp)
```c++
// C++ implementation of Radix Sort
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {-25, 2, 56, 234, 563246, -14325, 2345, -2345};
    int n = sizeof arr/sizeof(int);

    // Radix Sort
    // use 8-bit as radix
    for (int b = 0; b<4; ++b) {
        vector<int> v[256];
        for (int i = 0; i<n; ++i) {
            int idx = (arr[i]>>8*b)&0xFF;
            v[idx].push_back(arr[i]);
        }
        // included a sign bit
        if (b==3) {
            for (int i = 0; i<128; ++i) {
                vector<int> temp=v[i+128];
                v[i+128]=v[i];
                v[i]=temp;
            }
        }
        int i = 0;
        for (int idx = 0; idx<256; ++idx) {
            for (auto elem : v[idx]) {
                arr[i++]=elem;
            }
        }
    }
    for (int i : arr) {
        cout << i << ' ';
    }
    cout << '\n';

    return 0;
}
```

* [[BOJ] Heapsort](https://www.acmicpc.net/problem/2220) [(소스코드)](./src/heapsort.cpp) - 힙 소트의 성질을 이용한 문제
```c++
// https://www.acmicpc.net/problem/2220
#include <bits/stdc++.h>

using namespace std;
int main(void) 

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    static int arr[100'001];
    int n;
    cin>>n;

    /*
        1

        1         2
       2    ->   1

        2       2       3
       1 3  -> 3 1 ->  2 1
    */
    arr[1]=1;
    for (int i = 2; i<=n; ++i) {
        arr[i]=i;
        swap(arr[i-1],arr[i]);
        for (int j = i-1; j>1; j/=2) {
            swap(arr[j],arr[j/2]);
        }
    }
    for (int i = 1; i<=n; ++i) {
        cout << arr[i] << ' ';
    }

    return 0;
}

```


---
|[이전 - Greedy](/greedy/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Binary Search](/binary_search)|
|-|-|-|