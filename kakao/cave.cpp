#include <bits/stdc++.h>

using namespace std;

const int MAXN=2e5;
bool is_visited[MAXN];
int prior[MAXN],hang[MAXN];
vector<int> edge[MAXN];

void check(int i){
  if (is_visited[i]) {

    return;
  }
  if (!is_visited[prior[i]]) {
    hang[prior[i]] = i;

    return;
  }
  is_visited[i] = true;
  check(hang[i]);
  for (int j : edge[i]) {
    check(j);
  }

  return;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
  for(auto cur : path) {
      edge[cur[0]].push_back(cur[1]);
      edge[cur[1]].push_back(cur[0]);
  }
  for (auto cur : order) {
    prior[cur[1]] = cur[0]; // { 2, 1 } => 1 > 2
  }
  if (prior[0]) { // X -> 0

    return false;
  }
  is_visited[0] = true; // entry point
  for (int i : edge[0]) {
    check(i);
  }
  for (int i = 0; i < n; ++i) {
    if (!is_visited[i]) {

      return false;
    }
  }

  return true;
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<vector<int>> path = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
  vector<vector<int>> order = {{0,1},{0,3},{0,7},{8,1},{3,6},{1,2},{4,7},{7,5}};
  int n = 9;
  cout << solution(n, path, order);

  return 0;
}
