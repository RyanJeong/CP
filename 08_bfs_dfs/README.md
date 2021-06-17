# BFS_DFS

## BFS(Breadth-first search)
* 시작 정점으로부터 근접한 정점 우선 방문
* Queue 사용
* 추천 문제
	* [미로 탐색](https://www.acmicpc.net/problem/2178)
	* [영역 구하기](https://www.acmicpc.net/problem/2583)
	* [토마토](https://www.acmicpc.net/problem/7576)
	* [Elevator Trouble](https://www.acmicpc.net/problem/5014)

### 동작
* 시작 정점을 queue에 넣고, 방문했음을 기록
* Queue가 전부 비워질 때까지 아래 동작 반복:

1. Queue로부터 정점 하나를 가져옴
2. 정점의 근접 정점 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 조사 종료 
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 queue에 넣음과 동시에 방문했음을 기록

* 모든 정점이 queue에 한 번씩 들어가므로, 정점이 N개일 때의 시간 복잡도는 O(N)

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 가능
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 보장 
* Queue에 입력되는 정점은 시작 정점으로부터 거리 순임을 보장

## DFS(Depth-first search)
* 시작 정점으로부터 해당 분기 우선 방문
* Stack 또는 재귀함수 사용
* 추천 문제
	* [DFS와 BFS](https://www.acmicpc.net/problem/1260)
	* [바이러스](https://www.acmicpc.net/problem/2606)
	* [물통](https://www.acmicpc.net/problem/2251)
	* [Letters](https://www.acmicpc.net/problem/1987)

### 동작
* 시작 정점을 stack에 넣고, 방문했음을 기록
* Stack이 전부 비워질 때까지 아래 동작 반복: 
1. Stack으로부터 정점 하나를 가져옴
2. 정점의 근접 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 종료
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 stack에 넣음과 동시에 방문했음을 기록

* 모든 정점이 stack에 한 번씩 들어가므로, 정점이 N개일 때의 시간 복잡도는 O(N) 

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 <b>불가</b>
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 <b>보장하지 않음</b>