/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <string>
#include <queue>

// iostream
using std::cin;
using std::cout;

// string
using std::string;

// queue
using std::queue;

int main() {
  CP;

  const int cnt[] = {
    3, 2, 1, 2, 3, 3, 2, 3, 3, 2,
    2, 1, 2, 2, 1, 2, 2, 2, 1, 2,
    1, 1, 1, 2, 2, 1
  };
  string a, b;
  cin >> a >> b;
  queue<int> q;
  for (int i = 0; i < a.size(); ++i) {
    q.push(cnt[a[i]-'A']);
    q.push(cnt[b[i]-'A']);
  }
  while (q.size() > 2) {
    queue<int> temp;
    int prev = q.front();
    q.pop();
    while (!q.empty()) {
      int sum = prev + q.front();
      temp.push(sum % 10);
      prev = q.front();
      q.pop();
    }
    q = temp;
  }
  cout << q.front();
  q.pop();
  cout << q.front();

  return 0;
}
