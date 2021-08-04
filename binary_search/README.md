# Binary Search
* 추천 문제 - 이분 탐색
    * [[BOJ] LJUBOMORA](https://www.acmicpc.net/problem/2792) [(소스코드)](./src/marble.cpp) - [low, high) 조건 내 이분 탐색을 직접 구현한 예
    * [[BOJ] 좌표 압축](https://www.acmicpc.net/problem/18870) [(소스코드)](./src/compress.cpp)
    * [[BOJ] 세 수의 합](https://www.acmicpc.net/problem/2295) [(소스코드)](./src/sum_nums.cpp)
    * [[BOJ] 두 배열의 합](https://www.acmicpc.net/problem/2143) [(소스코드)](./src/matrix.cpp)
    * [[프로그래머스] 줄 서는 방법](https://programmers.co.kr/learn/courses/30/lessons/12936) [(소스코드)](./src/line.cpp) - 줄 서는 방법의 시간복잡도(`next_permutation()`)는 <b>O(<i>n</i>!)</b>이며, 이를 줄일 수 있는 방법
---

* 추천 문제 - 파라메트릭 서치
    * [[BOJ] 공유기 설치](https://www.acmicpc.net/problem/2110) - WIP
    * [[BOJ] 랜선 자르기](https://www.acmicpc.net/problem/1654) - WIP
    * [[BOJ] 휴게소 세우기](https://www.acmicpc.net/problem/1477) - WIP
    * [[BOJ] 숫자 구슬](https://www.acmicpc.net/problem/2613) - WIP
---

## 이분 탐색
* 정렬되어 있는 배열에서 특정 요소를 찾기 위해 모든 데이터를 순차적으로 탐색하는 것(선형탐색)이 아닌 탐색 범위를 절반으로 줄여가며 탐색하는 방법(이분탐색)
* 선형탐색의 시간복잡도는 <b>O(<i>n</i>)</b>
* 이분탐색의 시간복잡도는 <b>O(log <i>n</i>)</b>

## 이분 탐색 소스코드 (C)
```c
#include <string.h>
#include "key.h"

/* binsearch: find word in tab[0]...tab[n-1] */
struct key *binsearch(char *word, struct key tab[], int n)
{
    int cond;
    struct key *low  = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low<high) {
        mid=low+(high-low)/2; /* mid = (low + high) / 2 is WRONG! */
        if ((cond=strcmp(word, mid->word))<0) {
            high=mid;
        } else if (cond>0) {
            low=mid+1;
        } else {

            return mid;
        }
    }

    return NULL;
}
```

### 연습문제
* [[BOJ] 수 찾기](https://www.acmicpc.net/problem/1920) [(소스코드 1)](./src/bsearch1.cpp) [(소스코드 2)](./src/bsearch2.cpp)
###### Memory: 2,412 KB, Time: 60 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int m;
    cin>>m;
    while (m--) {
        int target;
        cin>>target;

        auto low = v.begin();
        auto high = v.end();
        while (low<high) {
            auto mid = low+(high-low)/2;
            if (target<*mid) {
                high=mid;
            }
            else if (*mid<target) {
                low=mid+1;
            }
            else {
                break;
            }
        }
        cout << ((low<high) ? 1 : 0) << '\n';
    }

    return 0;
}


```
###### Memory: 2,412 KB, Time: 56 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    int m;
    cin>>m;
    while (m--) {
        int target;
        cin>>target;

        cout << binary_search(v.begin(),v.end(),target) << '\n';
    }

    return 0;
}
```

## [`lower_bound`](https://www.cplusplus.com/reference/algorithm/lower_bound/)
* Returns an iterator pointing to the first element which does not compare less than <i>val</i>.
    * `it < val` 비교가 처음으로 거짓이 되는 곳
    * => `it >= val`
```c++
template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, 
                            ForwardIterator last, 
                            const T& val)
{
    ForwardIterator it;
    iterator_traits<ForwardIterator>::difference_type count, step;

    count=distance(first,last);
    while (count>0) {
        it=first; 
        step=count/2; 
        advance(it,step);
        if (*it<val) {
            first=++it;
            count-=step+1;
        }
        else {
            count=step;
        }
    }

    return first;
}
```

## [`upper_bound`](https://www.cplusplus.com/reference/algorithm/upper_bound/)
* Returns an iterator pointing to the first element which compares greater than <i>val</i>.
    * `it > val` 비교가 처음으로 참이 되는 곳
```c++
template <class ForwardIterator, class T>
ForwardIterator lower_bound(ForwardIterator first, 
                            ForwardIterator last, 
                            const T& val)
{
    ForwardIterator it;
    iterator_traits<ForwardIterator>::difference_type count, step;

    count=distance(first,last);
    while (count>0) {
        it=first; 
        step=count/2; 
        advance(it,step);
        if (!(val<*it)) {
            first=++it;
            count-=step+1;
        }
        else {
            count=step;
        }
    }

    return first;
}
```

### 연습문제
* [[BOJ] 숫자 카드 2](https://www.acmicpc.net/problem/10816) [(소스코드)](./src/card2.cpp)
###### Memory: 3,976 KB, Time: 316 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; ++i) {
        cin>>v[i];
    } 
    sort(v.begin(),v.end());

    int m;
    cin>>m;
    while (m--) {
        int t;
        cin>>t;

        cout << upper_bound(v.begin(),v.end(),t)-lower_bound(v.begin(),v.end(),t) << ' ';
    }    

    return 0;
}
```

## Parametric Search
* 이분 탐색 응용
* 최적화 문제, 이를테면 주어진 조건을 만족하는 값 중에서 최소 혹은 최대값을 구하는 문제를 <b>결정 문제</b>로 바꾸어 푸는 것
    * 이분 탐색을 사용해 탐색 범위를 줄여놓고, 주어진 조건에 만족하는 결과를 찾는 것



---
|[이전 - Sort](/sort/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Two Pointer](/two_pointer/)|
|-|-|-|
