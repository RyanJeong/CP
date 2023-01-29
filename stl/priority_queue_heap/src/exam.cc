/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <cstdlib>
#include <queue>

int main() {
  CP;

  std::priority_queue<int> pq;
  for (int i = 0; i < 10; ++i)
    pq.push(std::rand() % 100);

  while (!pq.empty()) {
    std::cout << pq.top() << '\n';
    pq.pop();
    /*
      93
      92
      86
      86
      83
      ...
    */
  }

  return 0;
}
