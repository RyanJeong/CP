#include <bits/stdc++.h>

using namespace std;

// for pair
#define X first  
#define Y second

int  arr[10][10]; // 0 ~ 4, OOB
bool is_visited[10][10]; // 0 ~ 4, OOB

// right -> bottom -> left -> top
int dx[4] = {  1,  0, -1,  0 };
int dy[4] = {  0,  1,  0, -1 }; 

vector<int> solution(vector<vector<string>> places) 
{
  vector<int>           answer;
  int                   n = 5;
  
  for (auto str : places) {
    int n_p = 0;
    memset(arr, 0, sizeof arr);
    memset(is_visited, false, sizeof is_visited);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        arr[i][j] = str[i][j] == 'P' ? 1 : (str[i][j] == 'O' ? 0 : -1);
        if (arr[i][j] == -1) {
          is_visited[i][j] = true;
        }
        if (arr[i][j] == 1) {
            ++n_p;
        }
      }
    }
    if (!n_p) {
      answer.push_back(1);
      continue;
    }
    bool is_safety = true;

    for (int i = 0; i < n && is_safety; ++i) {
      for (int j = 0; j < n && is_safety; ++j) {
        // 1 mark -> entry point
        if (arr[i][j] != 1 || is_visited[i][j]) {
          continue;
        }
        queue<pair<int, int>> q;
        int  base_x    = i;
        int  base_y    = j;

        is_visited[i][j] = true;
        q.push({ i, j });
        while (!q.empty()) {
          auto cur = q.front();

          q.pop();
          for (int k = 0; k < 4; ++k) {
            int x, y;

            x = cur.X + dx[k];
            y = cur.Y + dy[k];
            if (x < 0 || x >= n) {
              continue;
            }
            if (y < 0 || y >= n) {
              continue;
            }
            if (is_visited[x][y] || arr[x][y] == -1) {
              continue;
            }
            if (arr[x][y] == 1) {
              if (abs(base_x - x) + abs(base_y - y) <= 2) {
                if (base_x == x) {
                  int min_y = min(y, base_y);
                  if (arr[x][min_y+1] == -1) {
                    continue;
                  }
                } else if (base_y == y) {
                  int min_x = min(x, base_x);
                  if (arr[min_x+1][y] == -1) {
                    continue;
                  }
                }
                is_safety = false;
                break;
              } else {
                continue;
              }
            } else {
              is_visited[x][y] = true;
              q.push({ x, y });
            }
          }
          if (!is_safety) {
            break;
          }
        }
      }
    }
    answer.push_back(is_safety ? 1 : 0);
  }

  return answer;
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<string>> places = {
    {"XOOOX", "OOOOO", "OPXPO", "OOOOO", "XOOOX"}, // 1
    {"XOOOX", "OOOOO", "OOXOO", "OOOOO", "XOOOX"}, // 1
    {"XOOOX", "OOOOO", "OOXOO", "OOOOO", "XOOOX"}, // 1
    {"XPXPX", "PXPXP", "XXXXX", "XXXXX", "XXXXX"},  // 1
    {"OOOOO", "OOOOO", "OOOOO", "OOOOO", "OOOOO"}, // 1
    {"PPPPP", "PPPPP", "PPPPP", "PPPPP", "PPPPP"}, // 0
    {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, // 1
    {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, // 0
    {"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"}, // 1
    {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, // 1
    {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}, // 1
    {"XXXXX", "XXXXX", "XXXXX", "XXXXX", "XXXXX"}  // 1
   };
  vector<int> res{solution(places)};

  for (int i : res) {
    cout << i << ' '; 
  }

  return 0;
}