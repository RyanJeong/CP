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

// iostream
using std::cin;
using std::cout;

// queue
using std::priority_queue;

// vector
using std::vector;

// functional
using std::greater;

int main() {
  CP;

  int n;
  cin >> n;

  priority_queue<int, vector<int>, greater<int>> pq;
  const int kSize = n * n;
  for (int i = 0; i < kSize; ++i) {
    int temp;
    cin >> temp;

    pq.push(temp);
    if (pq.size() > n)
      pq.pop();
  }
  cout << pq.top();

  return 0;
}
