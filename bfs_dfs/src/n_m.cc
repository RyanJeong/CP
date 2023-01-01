/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <vector>

void Bt(int);

std::vector<int> arr;
std::vector<bool> is_visited;
int n, m;

int main() {
  CP;

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
