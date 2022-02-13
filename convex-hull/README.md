# [WIP] Convex Hull
* 추천 문제 - Convex Hull
    * [[BOJ] Convex Hull of Lattice Points](https://www.acmicpc.net/problem/2699) [(소스코드)](./src/convex_hull_of_lattice_points.cc) - Convex Hull 동작 방식 이해를 바탕으로 응용하는 문제
    * [[BOJ] Building the Moat](https://www.acmicpc.net/problem/6194) [(소스코드)](./src/building_the_moat.cc) - Convex Hull 알고리즘을 사용해 구한 다각형의 둘레를 계산하는 문제(1)
    * [[BOJ] Wall construction](https://www.acmicpc.net/problem/10903) [(소스코드)](./src/wall_construction.cc) - Convex Hull 알고리즘을 사용해 구한 다각형의 둘레를 계산하는 문제(2)
    * [[BOJ] Wall](https://www.acmicpc.net/problem/7420) [(소스코드)](./src/wall.cc) - Convex Hull 알고리즘을 사용해 구한 다각형의 둘레를 계산하는 문제(3) (반올림 주의)
    * [[BOJ] Cows](https://www.acmicpc.net/problem/6850) [(소스코드)](./src/cows.cc) - Convex Hull 알고리즘을 사용해 구한 다각형의 둘레를 계산하는 문제(4)
---

* 추천 문제 - Rotating Calipers
    * [[BOJ] Highway](https://www.acmicpc.net/problem/10254) [(소스코드)](./src/highway.cc)

---

* 추천 문제 - Point in Convex Polygon
    * [[WIP][BOJ] JABUKE](https://www.acmicpc.net/problem/2987) [(소스코드)](./src/jabuke.cc)

---

## Convex Hull
1. 2차원 평면 상에 좌표 <i>x</i>, <i>y</i>가 주어질 때, <i>y</i> 좌표를 기준으로 오름차순 정렬하되, <i>y</i> 좌표가 동일하다면 <i>x</i> 좌표를 기준으로 오름차순 정렬한다.
2. 기준 좌표(보통 0 번째 index를 기준으로 정함)를 기준으로 반시계 방향으로 정렬한다:
  * [CCW](#ccwcounterclockwise) 알고리즘을 사용했을 때 양수는 반시계 방향, 음수는 시계 방향을 나타냄
  * 만약 0이 나온다면, 기준 좌표로부터 가까운 거리 순으로 정렬
3. [Graham's Scan](https://en.wikipedia.org/wiki/Graham_scan)을 사용해 외곽 좌표를 찾는다:

   ![graham-s-scan](./img/GrahamScanDemo.gif)

### 연습문제
* [[BOJ] 볼록 껍질](https://www.acmicpc.net/problem/1708) [(소스코드)](./src/convex_hull.cc)
###### Memory: 2,808 KB, Time: 44 ms
```c++
/*
  Copyright 2021 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// iostream
using std::cin;
using std::cout;

// vector
using std::vector;

// utility
using std::pair;

// algorithm
using std::sort;

pair<int, int> starting_point;

bool CmpCoor(const pair<int, int>&,
             const pair<int, int>&);
bool CmpCcw(const pair<int, int>&,
            const pair<int, int>&);
int64_t CalcCcw(const pair<int, int>&,
                const pair<int, int>&,
                const pair<int, int>&);
int64_t CalcSqDist(const pair<int, int>&,
                   const pair<int, int>&);

int main() {
  CP;
  int n;
  cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; ++i)
    cin >> v[i].first >> v[i].second;

  // find the point with the lowest y-coordinate. (v[0], starting_point)
  sort(v.begin(), v.end(), CmpCoor);
  starting_point = v.front();
  // the set of points must be sorted in increasing order of the angle they and
  // the point P make with the x-axis
  sort(v.begin() + 1, v.end(), CmpCcw);

  // Graham's scan
  vector<pair<int, int>> convex_hull;
  for (const auto& p : v) {
    while (convex_hull.size() >= 2) {
      if (CalcCcw(convex_hull[convex_hull.size()-2], convex_hull.back(), p) > 0)
        break;
      convex_hull.pop_back();
    }
    convex_hull.push_back(p);
  }
  cout << convex_hull.size();

  return 0;
}

bool CmpCoor(const pair<int, int>& s,
             const pair<int, int>& t) {
  if (s.second < t.second)
    return true;

  if (s.second == t.second && s.first < t.first)
    return true;

  return false;
}

bool CmpCcw(const pair<int, int>& s,
            const pair<int, int>& t) {
  int64_t res = CalcCcw(starting_point, s, t);

  if (res)
    return res > 0;  // ccw : true, cw : false

  // res = 0
  int64_t dist1 = CalcSqDist(s, starting_point);
  int64_t dist2 = CalcSqDist(t, starting_point);

  return dist1 < dist2;
}

/* ccw         : pos.
   on the line : 0
   cw          : neg. */
int64_t CalcCcw(const pair<int, int>& a,
                const pair<int, int>& b,
                const pair<int, int>& c) {
  int64_t u1 = b.first - a.first;
  int64_t v1 = b.second - a.second;
  int64_t u2 = c.first - b.first;
  int64_t v2 = c.second - b.second;

  return u1 * v2 - u2 * v1;
}

int64_t CalcSqDist(const pair<int, int>& s,
                   const pair<int, int>& t) {
  int64_t diff_x = s.first - t.first;
  int64_t diff_y = s.second - t.second;

  return diff_x * diff_x + diff_y * diff_y;
}

```

## Rotating Calipers

### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

## Point in Convex Polygon

### 연습문제
* [[BOJ] ](https://www.acmicpc.net/problem/) [(소스코드)](./src/.cpp)
###### Memory:  KB, Time:  ms
```c++
```

---
|[이전 - String](/string/)|[목록](https://github.com/RyanJeong/CP#index)|다음 - 없음|
|-|-|-|

