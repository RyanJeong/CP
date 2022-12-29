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
#include <algorithm>

// curr_a, curr_b, curr_c
void dfs(int, int, int);

std::vector<std::vector<bool>> is_visited;
std::vector<int> res;
int a, b, c;

int main() {
  CP;

  std::cin >> a >> b >> c;

  is_visited = std::vector<std::vector<bool>>(201, std::vector<bool>(201));
  dfs(0, 0, c);
  std::sort(res.begin(), res.end());
  for (const int& i : res)
    std::cout << i << ' ';

  return 0;
}

void dfs(int curr_a, int curr_b, int curr_c) {
  if (is_visited[curr_a][curr_b])
    return;
  is_visited[curr_a][curr_b] = true;
  if (!curr_a)
    res.push_back(curr_c);

  // from a to b
  if (curr_a > b - curr_b)
    dfs(curr_a - (b - curr_b), b, curr_c);
  else
    dfs(0, curr_a + curr_b, curr_c);

  // from b to a
  if (curr_b > a - curr_a)
    dfs(a, curr_b - (a - curr_a), curr_c);
  else
    dfs(curr_a + curr_b, 0, curr_c);

  // from a to c (curr_a + curr_b + curr_c == c)
  dfs(0, curr_b, curr_a + curr_c);

  // from c to a
  if (curr_c > a - curr_a)
    dfs(a, curr_b, curr_c - (a - curr_a));
  else
    dfs(curr_a + curr_c, curr_b, 0);

  // from b to c (curr_a + curr_b + curr_c == c)
  dfs(curr_a, 0, curr_b + curr_c);

  // from c to b
  if (curr_c > b - curr_b)
    dfs(curr_a, b, curr_c - (b - curr_b));
  else
    dfs(curr_a, curr_b + curr_c, 0);
}
