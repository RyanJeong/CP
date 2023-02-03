# BFS & DFS
* 추천 문제 - BFS
  * [[BOJ] 전쟁 - 전투](https://www.acmicpc.net/problem/1303) [(소스코드)](./src/battle.cc) - 단순한 영역 개수 세기 문제 1 (y, x)
  * [[BOJ] Counting Sheep](https://www.acmicpc.net/problem/11123) [(소스코드)](./src/sheep.cc) - 단순한 영역 개수 세기 문제 2 (y, x)
  * [[BOJ] 쉬운 최단거리](https://www.acmicpc.net/problem/14940) [(소스코드)](./src/basic_min_dist.cc) - 단순한 영역 개수 세기 문제 3 (y, x)
  * [[BOJ] 와드](https://www.acmicpc.net/problem/23747) [(소스코드)](./src/ward.cc) - 단순한 영역 개수 세기 문제 4 (y, x)
  * [[BOJ] 경쟁적 전염](https://www.acmicpc.net/problem/18405) [(소스코드)](./src/competitive_contagion.cc) - 단계 별 BFS 순회 1 (y, x)
  * [[BOJ] 점프 게임](https://www.acmicpc.net/problem/15558) [(소스코드)](./src/jumping_game.cc) - 단계 별 BFS 순회 2 
  * [[BOJ] 구슬 탈출 2](https://www.acmicpc.net/problem/13460) [(소스코드)](./src/13460.cc) - 한 칸 이동이 아닌 경우 + 단계 별 BFS 순회 (y, x)
  * [[BOJ] 미로 탐색](https://www.acmicpc.net/problem/2178) [(소스코드)](./src/maze.cc) - `int` 벡터를 사용한 BFS 최단경로 문제
  * [[BOJ] koze](https://www.acmicpc.net/problem/3187) [(소스코드)](./src/koze.cc) - `bool` 벡터를 사용한 BFS 기본 응용문제
  * [[BOJ] 영역 구하기](https://www.acmicpc.net/problem/2583) [(소스코드)](./src/area.cc) - 2차원 평면 상에 분리되어 있는 영역의 수와 크기 구하기
  * [[BOJ] 토마토](https://www.acmicpc.net/problem/7576) [(소스코드)](./src/tomato.cc) - 최단경로 문제 응용 (이동 불가능한 조건)
  * [[BOJ] Elevator Trouble](https://www.acmicpc.net/problem/5014) [(소스코드)](./src/elevator.cc) - 1차원 BFS 최단경로 문회
  * [[BOJ] 벽 부수고 이동하기 4](https://www.acmicpc.net/problem/16946) [(소스코드)](./src/wall4.cc) - 영역 수를 미리 계산해 시간복잡도 줄이기
---

* 추천 문제 - DFS
  * [[BOJ] 바이러스](https://www.acmicpc.net/problem/2606) [(소스코드)](./src/virus.cc) - 재귀를 이용한 DFS
  * [[BOJ] 물통](https://www.acmicpc.net/problem/2251) [(소스코드)](./src/bottle.cc) - 재귀를 이용한 DFS + 구현 1
  * [[BOJ] 월드컵](https://www.acmicpc.net/problem/6987) [(소스코드)](./src/worldcup.cc) - 재귀를 이용한 DFS + 구현 2
    * 재귀에서 비용이 발생하는 지역변수들(예: `vector`)는 `static`을 사용하거나 **재귀에서만 접근 가능한 전역변수**로 선언할 것:
      * 재귀 내에 벡터를 지역변수로 선언한 경우(**시간초과**) [(소스코드)](./src/worldcup1.cc)
      * 재귀 내에 벡터를 `static`변수로 선언한 경우(492 ms) [(소스코드)](./src/worldcup2.cc)
      * 벡터를 재귀에서만 접근 가능하도록 선언한 경우(428 ms) [(소스코드)](./src/worldcup3.cc)
    * **제한시간이 짧은 경우 비용이 큰 방법을 다른 방법으로 대체해야 함**(`vector` -> 일반 배열 등)

---

* 추천 문제 - 백트래킹
  * [[BOJ] Back to the Barn](https://www.acmicpc.net/problem/1189) [(소스코드)](./src/back_to_the_barn.cc) - 단순한 백트래킹 + 영역탐색
  * [[BOJ] N-Queen](https://www.acmicpc.net/problem/9663) [(소스코드)](./src/n_queen.cc) - 백트래킹 + 구현 1
  * [[BOJ] 비숍](https://www.acmicpc.net/problem/1799) [(소스코드)](./src/bishop.cc) - 백트래킹 - 구현 2
  * [[BOJ] Sudoku](https://www.acmicpc.net/problem/2239) [(소스코드)](./src/sudoku.cc) - 백트래킹 - 구현 3
  * [[BOJ] Letters](https://www.acmicpc.net/problem/1987) [(소스코드)](./src/letters.cc) - 백트래킹 + 영역 탐색
---

## BFS(Breadth-first search)
* <b>가중치가 없는 최단 경로 문제 풀이에는 BFS를 사용해야 함</b>
* 시작 정점으로부터 근접한 정점 우선 방문
* `queue` 사용

## BFS 동작
* 시작 정점을 `queue`에 넣고, 방문했음을 기록
* `queue`가 전부 비워질 때까지 아래 동작 반복:

1. `queue`로부터 정점 하나를 가져옴
2. 정점의 근접 정점 조사:
  1. 해당 정점이 범위를 벗어난다면, 그대로 조사 종료 
  2. 해당 정점이 방문 상태라면, 그대로 조사 종료
  3. 해당 정점이 방문 전 상태라면, 해당 정점을 `queue`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `queue`에 한 번씩 들어가므로, 정점이 <i>N</i>개일 때의 시간 복잡도는 <b>O(<i>N</i>)</b>

## BFS 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 가능
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 보장 
* `queue`에 입력되는 정점은 시작 정점으로부터 거리 순임을 보장

### 연습문제
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) [(소스코드)](./src/canvas.cc) - BFS 사용
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

int main() {
  int r, c;
  std::cin >> r >> c;
  std::vector<std::vector<int>> v(r + 1, std::vector<int>(c + 1));
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j)
      std::cin >> v[i][j];
  }

  std::vector<std::vector<bool>> is_visited(r + 1, std::vector<bool>(c + 1));
  std::vector<int> areas;
  for (int i = 1; i <= r; ++i) {
    for (int j = 1; j <= c; ++j) {
      if (is_visited[i][j] || !v[i][j])
        continue;

      int area = 0;
      std::queue<std::pair<int, int>> q;
      q.push({i, j});
      is_visited[i][j] = true;
      while (!q.empty()) {
        ++area;
        auto cur = q.front();
        q.pop();

        // horizontally, vertically
        const std::vector<std::pair<int, int>> kAdj = {
          {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (const auto& d : kAdj) {
          int y = cur.first + d.first;
          int x = cur.second + d.second;

          if (y < 1 || y > r)
            continue;
          if (x < 1 || x > c)
            continue;
          if (is_visited[y][x] || !v[y][x])
            continue;
          q.push({y, x});
          is_visited[y][x] = true;
        }
      }
      areas.push_back(area);
    }
  }
  std::sort(areas.begin(), areas.end());
  std::cout << areas.size() << '\n' << ((!areas.empty()) ? areas.back() : 0);

  return 0;
}

```
---

## DFS(Depth-first search)
* 시작 정점으로부터 해당 분기 우선 방문
* `stack` 또는 재귀함수 사용

## DFS 동작
* 시작 정점을 `stack`에 넣고, 방문했음을 기록
* `stack`이 전부 비워질 때까지 아래 동작 반복: 
1. `stack`으로부터 정점 하나를 가져옴
2. 정점의 근접 조사:
  1. 해당 정점이 범위를 벗어난다면, 그대로 종료
  2. 해당 정점이 방문 상태라면, 그대로 조사 종료
  3. 해당 정점이 방문 전 상태라면, 해당 정점을 `stack`에 넣음과 동시에 방문했음을 기록

* 모든 정점이 `stack`에 한 번씩 들어가므로, 정점이 <i>N</i>개일 때의 시간 복잡도는 <b>O(<i>N</i>)</b>

## DFS 특징
* 주어진 모든 정점 순회 (flood fill 문제 해결 가능)
* 시작 정점과 종료 정점 간 최단 경로 계산 <b>불가</b>
* BFS는 모든 정점이 인접한 정점과의 거리 차가 1임을 <b>보장하지 않음</b>
* <b>다차원 배열에서의 flood fill은 BFS, DFS 둘 다 가능하지만, 다차원 배열에서의 최단경로 찾기는 BFS만 가능하므로, 다차원 배열에서의 순회 문제는 주로 BFS만 사용됨</b>

### 연습문제
* [[BOJ] DFS와 BFS](https://www.acmicpc.net/problem/1260) [(소스코드)](./src/dfs_bfs1.cc) - DFS(stack) 사용
```c++
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

void Dfs(int n, int v);
void Bfs(int n, int v);

std::vector<std::vector<int>> g;
std::vector<bool> is_visited;

int main() {
  int n, m, v;
  std::cin >> n >> m >> v;
  g = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1));
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }

  Dfs(n, v);
  std::cout << '\n';
  Bfs(n, v);

  return 0;
}

void Dfs(int n, int v) {
  std::stack<int> s;
  s.push(v);
  is_visited = std::vector<bool>(n + 1);
  while (!s.empty()) {
    auto cur = s.top();
    s.pop();

    if (is_visited[cur])
      continue;
    is_visited[cur] = true;
    std::cout << cur << ' ';
    // NOTICE: Search in reverse order considering the characteristics of the
    //         stack
    for (int i = n; i > 0; --i) {
      if (is_visited[i])
        continue;
      if (!g[cur][i])
        continue;
      s.push(i);
    }
  }

  return;
}

void Bfs(int n, int v) {
  std::queue<int> q;
  q.push(v);
  is_visited = std::vector<bool>(n + 1);
  is_visited[v] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    std::cout << cur << ' ';
    for (int i = 1; i <= n; ++i) {
      if (is_visited[i])
        continue;
      if (!g[cur][i])
        continue;
      q.push(i);
      is_visited[i] = true;
    }
  }

  return;
}

```
* [[BOJ] DFS와 BFS](https://www.acmicpc.net/problem/1260) [(소스코드)](./src/dfs_bfs2.cc) - DFS(recursion) 사용
```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

void Dfs(int n, int v);

std::vector<std::vector<int>> g;
std::vector<bool> is_visited;

int main() {
  int n, m, v;
  std::cin >> n >> m >> v;
  g = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1));
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    g[x][y] = g[y][x] = 1;
  }

  // dfs
  is_visited = std::vector<bool>(n + 1);
  Dfs(n, v);
  std::cout << '\n';

  // bfs
  std::queue<int> q;
  q.push(v);
  is_visited = std::vector<bool>(n + 1);
  is_visited[v] = true;
  while (!q.empty()) {
    auto cur = q.front();
    q.pop();

    std::cout << cur << ' ';
    for (int i = 1; i <= n; ++i) {
      if (is_visited[i])
        continue;
      if (!g[cur][i])
        continue;
      q.push(i);
      is_visited[i] = true;
    }
  }

  return 0;
}

void Dfs(int n, int v) {
  is_visited[v] = true;
  std::cout << v << ' ';
  for (int i = 1; i <= n; ++i) {
    if (is_visited[i])
      continue;
    if (!g[v][i])
      continue;
    Dfs(n, i);
  }

  return;
}

```

## Backtracking
* DFS(재귀)의 응용
* <b>Go as deeply as possible, backtrack if impossible</b>

### Backtracking과 DFS 차이
* 백트래킹: 탐색 중 후보해가 될 수 없는 경우(if impossible), 이전 단계로 돌아와 다른 후보해 탐색
* DFS: 모든 노드를 방문

### 연습문제
* [[BOJ] N과 M (1)](https://www.acmicpc.net/problem/15649) [(소스코드)](./src/n_m.cc)
```c++
#include <iostream>
#include <vector>

void Bt(int);

std::vector<int> arr;
std::vector<bool> is_visited;
int n, m;

int main() {
  std::cin >> n >> m;
  arr = std::vector<int>(n + 1);
  is_visited = std::vector<bool>(n + 1);
  Bt(0);

  return 0;
}

void Bt(int s) {
  if (s == m) {
    for (int i = 0; i < m; ++i)
      std::cout << arr[i] << ' ';
    std::cout <<'\n';

    return;
  }
  for (int i = 1; i <= n; ++i) {
    if (is_visited[i])
      continue;

    arr[s] = i;
    // Go as deeply as possible, backtrack if impossible
    is_visited[i] = true;
    Bt(s + 1);
    is_visited[i] = false;
  }

  return;
}

```

---
|[이전 - STL - Container Classes:](/stl/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Recursion](/recursion/)|
|-|-|-|