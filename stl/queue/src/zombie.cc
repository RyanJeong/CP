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

// iostream
using std::cin;
using std::cout;

// queue
using std::queue;

int main() {
  CP;

  int l;
  cin >> l;
  int m_l, m_k;
  cin >> m_l >> m_k;
  int c;
  cin >> c;
  int damage = 0;
  queue<int> q;
  bool is_true = true;
  for (int i = 1; i <= l; ++i) {
    if (!q.empty() && q.front() == i) {
      q.pop();
      damage -= m_k;
    }
    int hp;
    cin >> hp;
    if (hp > damage + m_k) {
      if (c > 0) {
        --c;
      } else {
        is_true = false;
        break;
      }
    } else {
      damage += m_k;
      q.push(i + m_l);
    }
  }
  cout << ((is_true) ? "YES" : "NO");

  return 0;
}
