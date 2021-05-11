// http://icpc.me/7569
#include <bits/stdc++.h>

using namespace std;

// for pair, z, x, y
#define Z first.first
#define X first.second
#define Y second

int arr[101][101][101]; //  1: object, 0: none
int day[101][101][101]; // -1: not used yet

// right -> bottom -> left -> top -> up -> down
int dx[6] = {  1,  0, -1,  0,  0,  0 };
int dy[6] = {  0,  1,  0, -1,  0,  0 }; 
int dz[6] = {  0,  0,  0,  0,  1, -1 }; 

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  queue<pair<pair<int, int>, int>> q;
  int                              m, n, h;

  cin >> m >> n >> h;
  // z -> x -> y
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < m; ++k) {
        cin >> arr[i][j][k];
        if (arr[i][j][k] == 1) {
          q.push( { { i, j }, k });
        } else if (arr[i][j][k] == 0) {
          day[i][j][k] = -1;
        }
      }
    }
  }
  while (!q.empty()) {
    auto cur = q.front();

    q.pop();
    for (int i = 0; i < 6; ++i) {
      int x, y, z;

      z = cur.Z + dz[i];
      x = cur.X + dx[i];
      y = cur.Y + dy[i];
      if (z < 0 || z >= h) {
        continue;
      }
      if (x < 0 || x >= n) {
        continue;
      }
      if (y < 0 || y >= m) {
        continue;
      }
      if (day[z][x][y] != -1) { // con't care
        continue;
      }
      day[z][x][y] = day[cur.Z][cur.X][cur.Y] + 1;
      q.push({ { z, x }, y });
    }
  }
  int  n_day;
  bool is_error;

  n_day    = 0;
  is_error = false;
  for (int i = 0; i < h && !is_error; ++i) {
    for (int j = 0; j < n && !is_error; ++j) {
      for (int k = 0; k < m && !is_error; ++k) {
        if (day[i][j][k] == -1) { // not spread accoress the area
          is_error = true;
          break;
        }
        n_day = max(n_day, day[i][j][k]);
      }
    }
  }
  cout << (is_error ? -1 : n_day);

  return 0;
}
