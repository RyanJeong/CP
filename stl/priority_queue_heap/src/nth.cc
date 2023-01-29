/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

int main() {
  CP;

  int n;
  std::cin >> n;

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  const int kSize = n * n;
  for (int i = 0; i < kSize; ++i) {
    int temp;
    std::cin >> temp;

    pq.push(temp);
    if (pq.size() > n)
      pq.pop();
  }
  std::cout << pq.top();

  return 0;
}
