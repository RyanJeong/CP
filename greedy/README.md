# Greedy
* 추천 문제
    * [[BOJ] 주유소](https://www.acmicpc.net/problem/13305) [(소스코드)](./src/gas_station.cpp)
    * [[BOJ] 멀티탭 스케줄링](https://www.acmicpc.net/problem/1700) [(소스코드)](./src/multitap.cpp)
    * [[BOJ] 중량제한](https://www.acmicpc.net/problem/1939) [(소스코드)](./src/weight_limit.cpp) - 분리집합을 이용한 문제
---

## 그리디 알고리즘
* 해를 구하기 위해 반복적으로 어떤 선택을 해야 하는 상황에서 가장 좋은(locally optimal) 것을 매번 선택하는 기법
    * 근시안적인 선택으로 부분적인 최적해를 찾고, 이들을 모아 문제에 대한 최적해를 얻는 것이 목적
    * 이러한 과정 중에 탐색 범위를 줄일 수 있음
* 그리디 알고리즘은 다음과 같은 절차를 거칠 때 이상적임
1. 주어진 문제에서 탐색 범위를 줄일 수 있는(시간복잡도를 줄일 수 있는) 방법이 있는지 고민한다. 
    * <b>상황을 단순하게 만들어 시간복잡도를 낮출 수 있는가?</b>
2. 해당 방법을 통해서도 올바른 해를 계산할 수 있음을 <b>수학적</b>으로 증명한다. 
    * 수학적인 증명이 어렵다면, 세운 가설이 올바르게 동작하는지 테스트케이스를 통해 확인한다.
3. 수학적인 증명이 완료되면, 해당 방법을 사용해 최적화된 방법으로 문제를 해결한다. 

### 연습문제
* [[BOJ] 동전 0](https://www.acmicpc.net/problem/11047) [(소스코드)](./src/coin.cpp)
###### Memory: 2,020 KB, Time: 0 ms
```c++
// https://www.acmicpc.net/problem/11047
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    // 동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 할 때,
    // 필요한 동전 개수의 최솟값을 구하라.

    // 가치가 높은 동전을 우선 사용하면, 필요한 동전 개수를
    // 최소로 할 수 있다. 
    // K 값이 600원이고, 주어진 동전 종류가 100원, 500원 두 가지
    // 가치가 낮은 동전을 우선 사용한다면, 100원 짜리 동전이
    // 6개 필요하다. 
    // 가치가 높은 동전을 우선 사용한다면, 500원 짜리 동전 하나와
    // 100원 짜리 동전 하나, 총 2개가 필요하다. 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin>>n>>k;
    vector<int> coin(n+1); // 1-based
    for (int i = 1; i<=n; ++i) {
        cin>>coin[i];
    }
    int res = 0;
    for (int i = n; i>0; --i) {
        res+=k/coin[i];
        k%=coin[i];
    }
    cout << res;

    return 0;
}
```

* [[BOJ] 회의실 배정](https://www.acmicpc.net/problem/1931) [(소스코드)](./src/meeting_room.cpp) - Task Scheduling Problem
###### Memory: 2,804 KB, Time: 28 ms
```c++
// https://www.acmicpc.net/problem/1931
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 
    // 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 
    // 회의의 최대 개수를 찾아보자.

    // 현재 시점보다 뒤에 시작하는 회의 중 가장 빨리 끝나는
    // 회의를 선택하면 최대 회의를 선택할 수 있지 않을까?
    // -> 회의 종료 시간을 기준으로 정렬

    int n;
    cin>>n;
    // {end-time, start-time}
    vector<pair<int, int>> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i].second>>v[i].first;
    }
    sort(v.begin(),v.end());

    int cnt = 0;
    int cur = 0;
    for (int i = 1; i<=n; ++i) {
        if (cur>v[i].second) {
            continue;
        }
        ++cnt;
        cur=v[i].first;
    }
    cout << cnt;

    return 0;
}
```

* [[BOJ] 로프](https://www.acmicpc.net/problem/2217) [(소스코드)](./src/rope.cpp)
###### Memory: 2,804 KB, Time: 28 ms
```c++
// https://www.acmicpc.net/problem/2217
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 각 로프들에 대한 정보가 주어졌을 때, 
    // 이 로프들을 이용하여 들어올릴 수 있는 
    // 물체의 최대 중량을 구해내는 프로그램을 
    // 작성하라.

    // 가장 무거운 중량을 견디는 로프부터 
    // 하나씩 추가하여 로프들이 견디는
    // 최대 중량 계산

    int n;
    cin>>n;
    vector<int> v(n+1);
    for (int i = 1; i<=n; ++i) {
        cin>>v[i];
    }
    sort(v.begin()+1,v.end(),greater<int>());
    int res=0;
    for (int i = 1; i<=n; ++i) {
        res=max(res,v[i]*i);
    }
    cout << res;

    return 0;
}
```

---
|[이전 - LIS & LCS](/lis_lcs/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Sort](/sort/)|
|-|-|-|
