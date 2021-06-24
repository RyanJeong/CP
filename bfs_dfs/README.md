# BFS_DFS

## BFS(Breadth-first search)
* 시작 정점으로부터 근접한 정점 우선 방문
* `queue` 사용
* 추천 문제
	* [미로 탐색](https://www.acmicpc.net/problem/2178) [(소스코드)](./src/maze.cpp)
	* [영역 구하기](https://www.acmicpc.net/problem/2583) [(소스코드)](./src/area.cpp)
	* [토마토](https://www.acmicpc.net/problem/7576) [(소스코드)](./src/tomato.cpp)
	* [Elevator Trouble](https://www.acmicpc.net/problem/5014) [(소스코드)](./src/210615_elevator.cpp)

### 동작
* 시작 정점을 `queue`에 넣고, 방문했음을 기록
* `queue`가 전부 비워질 때까지 아래 동작 반복:

1. `queue`로부터 정점 하나를 가져옴
2. 정점의 근접 정점 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 조사 종료 
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 `queue`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `queue`에 한 번씩 들어가므로, 정점이 `N`개일 때의 시간 복잡도는 `O(N)`

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 가능
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 보장 
* `queue`에 입력되는 정점은 시작 정점으로부터 거리 순임을 보장

## DFS(Depth-first search)
* 시작 정점으로부터 해당 분기 우선 방문
* `stack` 또는 재귀함수 사용
* 추천 문제
	* [DFS와 BFS](https://www.acmicpc.net/problem/1260) [(소스코드)](./src/210617_DFS_BFS.cpp)
	* [바이러스](https://www.acmicpc.net/problem/2606) [(소스코드)](./src/210617_DFS_virus.cpp)
	* [물통](https://www.acmicpc.net/problem/2251) [(소스코드)](./src/210617_DFS_bottle.cpp)
	* [Letters](https://www.acmicpc.net/problem/1987) [(소스코드)](./src/210617_DFS_letters.cpp)

### 동작
* 시작 정점을 `stack`에 넣고, 방문했음을 기록
* `stack`이 전부 비워질 때까지 아래 동작 반복: 
1. `stack`으로부터 정점 하나를 가져옴
2. 정점의 근접 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 종료
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 `stack`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `stack`에 한 번씩 들어가므로, 정점이 `N`개일 때의 시간 복잡도는 `O(N)` 

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 <b>불가</b>
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 <b>보장하지 않음</b>

---
|[이전 - STL - Container Classes:](../stl/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Recursion](../recursion/)|
|-|-|-|