# BFS & DFS
* 추천 문제 - BFS
    * [[BOJ] 미로 탐색](https://www.acmicpc.net/problem/2178) [(소스코드)](./src/maze.cpp) - `int` 벡터를 사용한 BFS 최단경로 문제
    * [[BOJ] koze](https://www.acmicpc.net/problem/3187) [(소스코드)](./src/koze.cpp) - `bool` 벡터를 사용한 BFS 기본 응용문제
    * [[BOJ] 점프 게임](https://www.acmicpc.net/problem/15558) [(소스코드)](./src/210628_jumping_game.cpp) - 단계 별 BFS 순회
    * [[BOJ] 영역 구하기](https://www.acmicpc.net/problem/2583) [(소스코드)](./src/area.cpp) - 2차원 평면 상에 분리되어 있는 영역의 수와 크기 구하기
    * [[BOJ] 토마토](https://www.acmicpc.net/problem/7576) [(소스코드)](./src/tomato.cpp) - 최단경로 문제 응용 (이동 불가능한 조건)
    * [[BOJ] Elevator Trouble](https://www.acmicpc.net/problem/5014) [(소스코드)](./src/210615_elevator.cpp) - 1차원 BFS 최단경로 문제
    * [[BOJ] 벽 부수고 이동하기 4](https://www.acmicpc.net/problem/16946) [(소스코드)](./src/210709_wall4.cpp)
---

* 추천 문제 - DFS - WIP
    * [[BOJ] DFS와 BFS](https://www.acmicpc.net/problem/1260) [(소스코드)](./src/210617_DFS_BFS.cpp)
    * [[BOJ] 바이러스](https://www.acmicpc.net/problem/2606) [(소스코드)](./src/210617_DFS_virus.cpp)
    * [[BOJ] 물통](https://www.acmicpc.net/problem/2251) [(소스코드)](./src/210617_DFS_bottle.cpp)
    * [[BOJ] Letters](https://www.acmicpc.net/problem/1987) [(소스코드)](./src/210617_DFS_letters.cpp)
---

* 추천 문제 - 백트래킹 - WIP
    * [[BOJ] N-Queen](https://www.acmicpc.net/problem/9663) [(소스코드)](./backtracking/src/n_queen.cpp)
    * [[BOJ] 비숍](https://www.acmicpc.net/problem/1799) [(소스코드)](./backtracking/src/210618_bishop.cpp)
    * [[BOJ] Sudoku](https://www.acmicpc.net/problem/2239) [(소스코드)](./backtracking/src/210712_sudoku.cpp)
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
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) [(소스코드)](./src/canvas.cpp) - BFS 사용
###### Memory: 3,980 KB, Time: 36 ms
```c++
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n+1,vector<int>(m+1));
    vector<vector<bool>> is_visited(n+1,vector<bool>(m+1));
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            cin>>v[i][j];
        }
    }

    vector<int> areas;
    for (int i = 1; i<=n; ++i) {
        for (int j = 1; j<=m; ++j) {
            if (is_visited[i][j] || !v[i][j]) {
                continue;
            }

            int area = 0;
            queue<pair<int, int>> q;
            q.push({i,j});
            is_visited[i][j]=true;
            while (!q.empty()) {
                ++area;
                auto cur = q.front();
                q.pop();

                for (int d = 0; d<4; ++d) {
                    const int dx[] = {1,0,-1,0};
                    const int dy[] = {0,1,0,-1}; 

                    int x = cur.first+dx[d];
                    int y = cur.second+dy[d];
                    if (x<1 || x>n) {
                        continue;
                    }
                    if (y<1 || y>m) {
                        continue;
                    }
                    if (is_visited[x][y] || !v[x][y]) {
                        continue;
                    }
                    q.push({x,y});
                    is_visited[x][y]=true;
                }
            }
            areas.push_back(area);
        }
    }
    sort(areas.begin(),areas.end());
    cout << areas.size()  << '\n' << ((!areas.empty()) ? areas.back() : 0);

    return 0;
}
```
---

## DFS(Depth-first search) - WIP
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
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) [(소스코드)](./src/dfs_canvas.cpp) - DFS(stack) 사용
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
* [[BOJ] 그림](https://www.acmicpc.net/problem/1926) [(소스코드)](./src/dfs_rec_canvas.cpp) - DFS(recursion) 사용
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

## Backtracking - WIP
* DFS(재귀)의 응용
* <b>Go as deeply as possible, backtrack if impossible</b>

### 연습문제
* [[BOJ] N과 M (1)](https://www.acmicpc.net/problem/15649) [(소스코드)](./backtracking/src/n_m.cpp)
###### Memory: 2,016 KB, Time: 24 ms
```c++
// https://www.acmicpc.net/problem/15649
#include <bits/stdc++.h>

using namespace std;

void bt(int);

int n, m;
int arr[9]; // 0, 1 ~ 8
bool is_used[9];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    bt(0);

    return 0;
}

void bt(int s)
{
    if (s==m) {
        for (int i = 0; i<m; ++i) {
            cout << arr[i] << ' ';
        }
        cout <<'\n';

        return;
    }
    for (int i = 1; i<=n; ++i) {
        if (!is_used[i]) {
            arr[s]=i;
            // Go as deeply as possible, backtrack if impossible
            is_used[i]=true;
            bt(s+1);
            is_used[i]=false;
        }
    }

    return;
}
```

---
|[이전 - STL - Container Classes:](/stl/)|[목록](https://github.com/RyanJeong/CP#index)|[다음 - Recursion](/recursion/)|
|-|-|-|