# Binary Search
* 추천 문제
    * [[BOJ] 휴게소 세우기](https://www.acmicpc.net/problem/1477) [(소스코드)](./src/rest_area.cpp)
    * [[BOJ] 두 배열의 합](https://www.acmicpc.net/problem/2143) [(소스코드)](./src/matrix.cpp)
    * [[프로그래머스] 줄 서는 방법](https://programmers.co.kr/learn/courses/30/lessons/12936) [(소스코드)](./src/line.cpp) - 줄 서는 방법의 시간복잡도(`next_permutation()`)는 <b>O(<i>n</i>!)</b>이며, 이를 줄일 수 있는 방법
---

## 이분 탐색
* 정렬되어 있는 배열에서 특정 요소를 찾기 위해 모든 데이터를 순차적으로 탐색하는 것(선형탐색)이 아닌 탐색 범위를 절반으로 줄여가며 탐색하는 방법(이분탐색)
* 선형탐색의 시간복잡도는 <b>O(<i>n</i>)</b>
* 이분탐색의 시간복잡도는 <b>O(log <i>n</i>)</b>

## 이분 탐색 소스코드
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
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++


* [WIP]`lower_bound`
    * Returns an iterator pointing to the first element which does not compare less than <i>val</i>.
    * `elem < val` 비교가 처음으로 거짓이 되는 곳
    * => `elem >= val`

* `upper_bound`
    * Returns an iterator pointing to the first element which compares greater than <i>val</i>.
    * `elem > val` 비교가 처음으로 참이 되는 곳


### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - Sort](/sort/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Two Pointer](/two_pointer/)|
|-|-|-|
