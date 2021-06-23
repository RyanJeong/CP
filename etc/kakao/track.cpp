#include <bits/stdc++.h>
 
using namespace std;
 
typedef struct {
  int x;
  int y;
  int cost;
  int dir;
} Car;

// right -> bottom -> left -> top
int dx[4] = {  1,  0, -1,  0 };
int dy[4] = {  0,  1,  0, -1 }; 
 
int solution(vector<vector<int>> board) {
  int answer = 2e9;
  int n      = board.size();
  queue<Car> q;
  Car        c{ 0, 0, 0, -1 }; // -1: start

  q.push(c);
  board[0][0] = 1; // start marking

  while (!q.empty()) {
    auto cur = q.front();

    q.pop();
    for (int k = 0; k < 4; ++k) {
      int x, y;

      x = cur.x + dx[k];
      y = cur.y + dy[k];
      if (x < 0 || x >= n) {
        continue;
      }
      if (y < 0 || y >= n) {
        continue;
      }
      if (board[x][y] == 1) {  // Wall
        continue;
      }
      int cost = 0;

      if (cur.dir == -1 || cur.dir == k) {
        cost = cur.cost + 100;
      } else if (cur.dir != k) {
        cost = cur.cost + 600;
      }
      if (board[x][y] == 0 || board[x][y] >= cost) {
        Car new_c{ x, y, cost, k };

        board[x][y] = cost;
        q.push(new_c);
      }
    }
  }
  answer = board[n-1][n-1];

  return answer;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> board = {{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0},{1,0,0,0,0,0,0,0}};
  cout << solution(board);

  return 0;
}