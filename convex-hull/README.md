# [WIP] Convex Hull
* 추천 문제 - Convex Hull
    * [[BOJ] 볼록 껍질](https://www.acmicpc.net/problem/1708) [(소스코드)](./src/convex_hull.cc)
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

