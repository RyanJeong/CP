# BFS_DFS

## BFS(Breadth-first search)
* 시작 정점으로부터 근접한 정점 우선 방문
* `queue` 사용
* 추천 문제
	* [[BOJ] 미로 탐색](https://www.acmicpc.net/problem/2178) [(소스코드)](./src/maze.cpp)
	* [[BOJ] 영역 구하기](https://www.acmicpc.net/problem/2583) [(소스코드)](./src/area.cpp)
	* [[BOJ] 토마토](https://www.acmicpc.net/problem/7576) [(소스코드)](./src/tomato.cpp)
	* [[BOJ] Elevator Trouble](https://www.acmicpc.net/problem/5014) [(소스코드)](./src/210615_elevator.cpp)

### 동작
* 시작 정점을 `queue`에 넣고, 방문했음을 기록
* `queue`가 전부 비워질 때까지 아래 동작 반복:

1. `queue`로부터 정점 하나를 가져옴
2. 정점의 근접 정점 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 조사 종료 
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 `queue`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `queue`에 한 번씩 들어가므로, 정점이 <i>N</i>개일 때의 시간 복잡도는 <b>O(<i>N</i>)</b>

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 가능
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 보장 
* `queue`에 입력되는 정점은 시작 정점으로부터 거리 순임을 보장

### 코드
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) - BFS 사용
###### Memory: 3,248 KB, Time: 24 ms
```c++
// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 1: object, 0: none
	static int arr[501][501];        
	// 1: true,   0: false
	static bool is_visited[501][501];
	// right -> bottom -> left -> top
	const int dx[] = {1,0,-1,0};
	const int dy[] = {0,1,0,-1}; 

	int n, m;
	cin>>n>>m;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			cin>>arr[i][j];
		}
	}

	int max_area = 0;
	int n_picture = 0;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			if (is_visited[i][j] || !arr[i][j]) {
				continue;
			}
			int area = 0;
			++n_picture;
			queue<pair<int, int>> q;
			q.push({i,j});
			is_visited[i][j]=true;
			
			while (!q.empty()) {
				++area;
				auto cur = q.front();
				q.pop();
				for (int d = 0; d<4; ++d) {
					int x = cur.first+dx[d];
					int y = cur.second+dy[d];
					if (x<1 || x>n) {
						continue;
					}
					if (y<1 || y>m) {
						continue;
					}
					if (is_visited[x][y] || !arr[x][y]) {
						continue;
					}
					q.push({x,y});
					is_visited[x][y]=true;
				}
			}
			max_area = max(max_area, area);
		}
	}
	cout << n_picture << '\n' << max_area;

	return 0;
}
```

## DFS(Depth-first search)
* 시작 정점으로부터 해당 분기 우선 방문
* `stack` 또는 재귀함수 사용
* 추천 문제
	* [[BOJ] DFS와 BFS](https://www.acmicpc.net/problem/1260) [(소스코드)](./src/210617_DFS_BFS.cpp)
	* [[BOJ] 바이러스](https://www.acmicpc.net/problem/2606) [(소스코드)](./src/210617_DFS_virus.cpp)
	* [[BOJ] 물통](https://www.acmicpc.net/problem/2251) [(소스코드)](./src/210617_DFS_bottle.cpp)
	* [[BOJ] Letters](https://www.acmicpc.net/problem/1987) [(소스코드)](./src/210617_DFS_letters.cpp)

### 동작
* 시작 정점을 `stack`에 넣고, 방문했음을 기록
* `stack`이 전부 비워질 때까지 아래 동작 반복: 
1. `stack`으로부터 정점 하나를 가져옴
2. 정점의 근접 조사:
	1. 해당 정점이 범위를 벗어난다면, 그대로 종료
	2. 해당 정점이 방문 상태라면, 그대로 조사 종료
	3. 해당 정점이 방문 전 상태라면, 해당 정점을 `stack`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `stack`에 한 번씩 들어가므로, 정점이 <i>N</i>개일 때의 시간 복잡도는 <b>O(<i>N</i>)</b>

### 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 <b>불가</b>
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 <b>보장하지 않음</b>
* <b>다차원 배열에서의 flood fill은 BFS, DFS 둘 다 가능하지만, 다차원 배열에서의 최단경로 찾기는 BFS만 가능하므로, 다차원 배열에서의 순회 문제는 주로 BFS만 사용됨</b>

### 코드
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) - DFS(stack) 사용
###### Memory: 4,312 KB, Time: 24 ms
```c++
// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 1: object, 0: none
	static int arr[501][501];        
	// 1: true,   0: false
	static bool is_visited[501][501];
	// right -> bottom -> left -> top
	const int dx[] = {1,0,-1,0};
	const int dy[] = {0,1,0,-1}; 

	int n, m;
	cin>>n>>m;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			cin>>arr[i][j];
		}
	}

	int max_area = 0;
	int n_picture = 0;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			if (is_visited[i][j] || !arr[i][j]) {
				continue;
			}
			int area = 0;
			++n_picture;
			stack<pair<int, int>> s;
			s.push({i,j});
			is_visited[i][j]=true;
			
			while (!s.empty()) {
				++area;
				auto cur = s.top();
				s.pop();
				for (int d = 0; d<4; ++d) {
					int x = cur.first+dx[d];
					int y = cur.second+dy[d];
					if (x<1 || x>n) {
						continue;
					}
					if (y<1 || y>m) {
						continue;
					}
					if (is_visited[x][y] || !arr[x][y]) {
						continue;
					}
					s.push({x,y});
					is_visited[x][y]=true;
				}
			}
			max_area = max(max_area, area);
		}
	}
	cout << n_picture << '\n' << max_area;

	return 0;
}
```
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) - DFS(recursion) 사용
###### Memory: 14,840 KB, Time: 28 ms
```c++
// https://www.acmicpc.net/problem/1926
#include <bits/stdc++.h>

using namespace std;

int dfs(int, int);

// 1: object, 0: none
static int arr[501][501];        
// 1: true,   0: false
static bool is_visited[501][501];
// right -> bottom -> left -> top
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1}; 

int n, m;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			cin>>arr[i][j];
		}
	}

	int max_area = 0;
	int n_picture = 0;
	for (int i = 1; i<=n; ++i) {
		for (int j = 1; j<=m; ++j) {
			if (is_visited[i][j] || !arr[i][j]) {
				continue;
			}
			int area = dfs(i,j);
			++n_picture;
			max_area = max(max_area,area);
		}
	}
	cout << n_picture << '\n' << max_area;

	return 0;
}

int dfs(int i, int j)
{
	int area = 1;
	is_visited[i][j]=true;
	
	for (int d = 0; d<4; ++d) {
		int x = i+dx[d];
		int y = j+dy[d];
		if (x<1 || x>n) {
			continue;
		}
		if (y<1 || y>m) {
			continue;
		}
		if (is_visited[x][y] || !arr[x][y]) {
			continue;
		}
		area+=dfs(x,y);
	}

	return area;
}
```

---
|[이전 - STL - Container Classes:](../stl/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Recursion](../recursion/)|
|-|-|-|