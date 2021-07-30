# Two Pointer
* 추천 문제
    * [[BOJ] Subsequence](https://www.acmicpc.net/problem/1806) [(소스코드)](./src/210712_subsequence.cpp) - 두 포인터를 이용해 조건을 만족하는 구간을 찾는 문제
    * [[BOJ] 용액 합성하기](https://www.acmicpc.net/problem/14921) [(소스코드)](./src/210712_two_liquids.cpp) - 탐색 대상이 정렬되었을 때의 두 포인터 사용 예
    * [[BOJ] 세 용액](https://www.acmicpc.net/problem/2473) [(소스코드)](./src/210712_two_liquids.cpp) - 세 포인터 예
---

## 두 포인터
* 두 개의 포인터를 이용해 만족하는 구간을 찾는 알고리즘
* <b>상한(`high`) 조건에 유의할 것</b>
* 이중 `for`문을 사용할 경우, 시간복잡도가 <b>O(<i>n</i><sup>2</sup>)</b>이지만, 두 포인터를 사용할 경우 시간 복잡도를 <b>O(<i>n</i>)</b>로 줄일 수 있음 

### 연습문제
* [[BOJ] 수들의 합 2](https://www.acmicpc.net/problem/2003) [(소스코드)](./src/210712_exer1.cpp) - 이중 `for`문
###### Memory: 20,60 KB, Time: 32 ms
```c++
// https://www.acmicpc.net/problem/2003
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[10'000];
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    int res = 0;
    for (int i = 0; i<n; ++i) {
        int sum = 0;
        for (int j = i; j<n; ++j) {
            sum+=arr[j];
            if (sum==m) {
                ++res;
            }
            else if (sum>m) {
                break;
            }
        }
    }
    cout << res;

    return 0;
}
```

* [[BOJ] 수들의 합 2](https://www.acmicpc.net/problem/2003) [(소스코드)](./src/210712_exer2.cpp) - 두 포인터
###### Memory: 20,60 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/2003
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    static int arr[10'000];
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<n; ++i) {
        cin>>arr[i];
    }

    int low = 0;
    int high = 0;
    int res = 0;
    int sum = 0;
    while (low<=high) {
        if (sum>m) {
            sum-=arr[low++];
        } 
        else {
            if (sum==m) {
                ++res;
            }
            // 0 1 2 3 '4'
            // if high point to '4' -> break!
            if (high==n) {
                break;
            }
            sum+=arr[high++];
        }
    }
    cout << res;

    return 0;
}
```

---
|[이전 - Binary Search](/binary_search/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - String](/string/)|
|-|-|-|