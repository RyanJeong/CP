/*
  Copyright 2022 Ryan M. Jeong <ryan.m.jeong@hotmail.com>
*/

// CP
#define CP do {                     \
  std::ios::sync_with_stdio(false); \
  std::cin.tie(NULL);               \
} while (0)

#include <iostream>
#include <deque>

// iostream
using std::cin;
using std::cout;

// deque
using std::deque;

int main() {
  CP;

  int n, m;
  cin >> n >> m;
  deque<int> dq;
  while (n)
    dq.push_front(n--);

  int res = 0;
  while (m--) {
    int num;
    cin >> num;

    int tmp;
    for (int i = 0; i < dq.size(); ++i) {
      if (num == dq[i]) {
        tmp = i;
        break;
      }
    }

    while (true) {
      if (num == dq.front()) {
        dq.pop_front();
        break;
      } else {
        ++res;
        if (tmp * 2 < dq.size()) {
          dq.push_back(dq.front());
          dq.pop_front();
        } else {
          dq.push_front(dq.back());
          dq.pop_back();
        }
      }
    }
  }
  cout << res;

  return 0;
}
